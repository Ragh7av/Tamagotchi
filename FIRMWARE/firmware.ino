#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

// Pin layout directly mapping image_2026-06-25_181045654.png
#define PIN_BTN_LEFT   0  // SW4
#define PIN_BTN_SELECT 1  // SW5
#define PIN_BTN_RIGHT  2  // SW6
#define PIN_BUZZER     3  // BZ1
#define I2C_SDA        9  // U2 SDA
#define I2C_SCL        8  // U2 SCL

// Core Stats
int hunger = 60;       
int happiness = 50;    
int energy = 100;      // New Energy Stat (0-100)

// State Machine
int selectedMenu = 0;  // 0 = FEED, 1 = PLAY, 2 = SLEEP
bool showStatus = false;
bool isSleeping = false;
bool inGame = false;

// Mini-Game Variables
int paddleX = 54;
int itemX = 30;
int itemY = 12;
int gameScore = 0;
int itemsDropped = 0;

unsigned long lastStatTick = 0;
const unsigned long TICK_INTERVAL = 6000; // Stat updates every 6 seconds

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void playBeep(int frequency, int duration) {
  long delayVal = 1000000 / frequency / 2;
  long numCycles = (long)frequency * duration / 1000;
  for (long i = 0; i < numCycles; i++) {
    digitalWrite(PIN_BUZZER, HIGH);
    delayMicroseconds(delayVal);
    digitalWrite(PIN_BUZZER, LOW);
    delayMicroseconds(delayVal);
  }
}

void setup() {
  pinMode(PIN_BTN_LEFT, INPUT_PULLUP);
  pinMode(PIN_BTN_SELECT, INPUT_PULLUP);
  pinMode(PIN_BTN_RIGHT, INPUT_PULLUP);
  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_BUZZER, LOW);

  Wire.begin(I2C_SDA, I2C_SCL);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(35, 28);
  display.print("PET OS v2.0");
  display.display();
  delay(1000);
  
  lastStatTick = millis();
}

void loop() {
  // --- 1. Passive Background Stat Management ---
  if (millis() - lastStatTick >= TICK_INTERVAL) {
    lastStatTick = millis();
    
    if (isSleeping) {
      energy += 15;
      if (energy >= 100) {
        energy = 100;
        isSleeping = false; // Automatically wakes up fully charged
        playBeep(1500, 400);
      }
    } else {
      if (hunger > 0) hunger -= 3;
      if (happiness > 0) happiness -= 3;
      if (energy > 0) energy -= 2; // Slow active drain
    }
  }

  // --- 2. Handle Inputs & States ---
  if (inGame) {
    runMiniGameLoop();
  } else if (isSleeping) {
    // Pressing any button wakes the pet early
    if (digitalRead(PIN_BTN_LEFT) == LOW || digitalRead(PIN_BTN_SELECT) == LOW || digitalRead(PIN_BTN_RIGHT) == LOW) {
      isSleeping = false;
      playBeep(1000, 100);
      delay(300);
    }
    drawSleepScreen();
  } else {
    handleStandardInput();
    
    display.clearDisplay();
    if (showStatus) {
      drawStatusScreen();
    } else {
      drawMainScreen();
    }
    display.display();
  }
  
  delay(30); // Global frame limiter
}

// --- Standard UI Input Controller ---
void handleStandardInput() {
  if (digitalRead(PIN_BTN_LEFT) == LOW) {
    selectedMenu = (selectedMenu + 1) % 3; // Loop between 0, 1, 2
    playBeep(1800, 30);
    delay(200); 
  }

  if (digitalRead(PIN_BTN_RIGHT) == LOW) {
    showStatus = !showStatus; 
    playBeep(1400, 40);
    delay(200);
  }

  if (digitalRead(PIN_BTN_SELECT) == LOW) {
    delay(200);
    if (selectedMenu == 0) { // FEED
      hunger = min(hunger + 20, 100);
      playBeep(900, 80); delay(40); playBeep(700, 80);
    } 
    else if (selectedMenu == 1) { // PLAY
      if (energy >= 20) {
        // Init the Mini-game state
        inGame = true;
        gameScore = 0;
        itemsDropped = 0;
        paddleX = 54;
        itemY = 12;
        itemX = random(10, 110);
        playBeep(1200, 100);
      } else {
        // Too tired warning!
        playBeep(300, 300); 
      }
    } 
    else if (selectedMenu == 2) { // SLEEP
      isSleeping = true;
      showStatus = false;
      playBeep(600, 200); delay(50); playBeep(400, 300);
    }
  }
}

// --- Arcade Mini-Game Implementation ---
void runMiniGameLoop() {
  // Input tracking directly inside the game
  if (digitalRead(PIN_BTN_LEFT) == LOW && paddleX > 0) {
    paddleX -= 5;
  }
  if (digitalRead(PIN_BTN_RIGHT) == LOW && paddleX < 112) {
    paddleX += 5;
  }

  // Drop object physics
  itemY += 2;

  // Collision handling (Paddle sits at Y=56)
  if (itemY >= 54) {
    if (itemX >= paddleX && itemX <= (paddleX + 16)) {
      gameScore++;
      playBeep(2200, 50); // High pitch catch indicator
    } else {
      playBeep(400, 80);  // Low pitch miss indicator
    }
    
    // Spawn next object
    itemY = 12;
    itemX = random(5, 120);
    itemsDropped++;
  }

  // Check End Game Condition (After 5 drops)
  if (itemsDropped >= 5) {
    inGame = false;
    energy = max(energy - 20, 0); // Discharge tax for playing
    happiness = min(happiness + (gameScore * 12), 100); // Reward calculations
    
    // Victory fanfare
    playBeep(1500, 80); delay(50);
    playBeep(2000, 150);
    return;
  }

  // Render Mini Game Screen
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Score:"); display.print(gameScore);
  display.setCursor(85, 0);
  display.print("Drop:"); display.print(itemsDropped + 1);
  display.drawLine(0, 10, 128, 10, SSD1306_WHITE);

  // Draw Catch Basket Paddle
  display.fillRect(paddleX, 56, 16, 4, SSD1306_WHITE);
  // Draw Falling Fruit/Object
  display.fillCircle(itemX, itemY, 3, SSD1306_WHITE);
  display.display();
}

// --- UI Display Render Panels ---
void drawMainScreen() {
  // Menu Options Rendering
  display.drawRect(2, 2, 38, 13, SSD1306_WHITE);
  display.drawRect(44, 2, 38, 13, SSD1306_WHITE);
  display.drawRect(86, 2, 40, 13, SSD1306_WHITE);
  
  if (selectedMenu == 0) display.fillRect(2, 2, 38, 13, SSD1306_INVERSE);
  if (selectedMenu == 1) display.fillRect(44, 2, 38, 13, SSD1306_INVERSE);
  if (selectedMenu == 2) display.fillRect(86, 2, 40, 13, SSD1306_INVERSE);

  display.setCursor(8, 5);   display.print("FEED");
  display.setCursor(52, 5);  display.print("PLAY");
  display.setCursor(92, 5);  display.print("SLEEP");

  int bounce = (millis() % 800 < 400) ? 0 : 2;
  display.drawRoundRect(48, 25 + bounce, 32, 26, 6, SSD1306_WHITE); // Body

  if (energy < 20) {
    // Exhausted/Dying Expression
    display.setCursor(55, 32 + bounce); display.print("=");
    display.setCursor(67, 32 + bounce); display.print("=");
    display.drawLine(59, 44 + bounce, 67, 44 + bounce, SSD1306_WHITE);
  } else {
    // Normal Face
    display.fillRect(55, 34 + bounce, 3, 3, SSD1306_WHITE);
    display.fillRect(69, 34 + bounce, 3, 3, SSD1306_WHITE);
    display.drawPixel(61, 42 + bounce, SSD1306_WHITE);
    display.drawPixel(65, 42 + bounce, SSD1306_WHITE);
  }
}

void drawSleepScreen() {
  display.clearDisplay();
  int pulse = (millis() % 2000 < 1000);
  
  // Snoozing animations
  display.setCursor(85, 20 - (pulse * 3)); display.print(pulse ? "Zzz" : "zZz");
  
  // Closed eyes pet body representation
  display.drawRoundRect(48, 30, 32, 26, 6, SSD1306_WHITE);
  display.drawLine(54, 39, 58, 39, SSD1306_WHITE); // Closed Left Eye
  display.drawLine(68, 39, 72, 39, SSD1306_WHITE); // Closed Right Eye
  
  display.setCursor(20, 3);
  display.print("Recharging energy...");
  display.display();
}

void drawStatusScreen() {
  display.setCursor(32, 2);
  display.print("PET VITALS");
  display.drawLine(0, 12, 128, 12, SSD1306_WHITE);

  // Hunger Meter
  display.setCursor(2, 18);  display.print("HUNGER");
  display.drawRect(50, 18, 70, 7, SSD1306_WHITE);
  display.fillRect(52, 20, (hunger * 66) / 100, 3, SSD1306_WHITE);

  // Happiness Meter
  display.setCursor(2, 32);  display.print("HAPPY");
  display.drawRect(50, 32, 70, 7, SSD1306_WHITE);
  display.fillRect(52, 34, (happiness * 66) / 100, 3, SSD1306_WHITE);

  // Energy Discharge Meter
  display.setCursor(2, 46);  display.print("ENERGY");
  display.drawRect(50, 46, 70, 7, SSD1306_WHITE);
  display.fillRect(52, 48, (energy * 66) / 100, 3, SSD1306_WHITE);
}
