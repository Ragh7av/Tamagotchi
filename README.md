 <h1 align="center">Tamagotchi</h1>
 <img width="1642" height="951" alt="Screenshot 2026-06-21 043140" src="https://github.com/user-attachments/assets/c41d5591-320c-42f1-a650-d778b82fd9f7" />

<div align="center">         
<p align="center">
A custom, pocket-sized virtual pet built with a XIAO ESP32C3, an OLED display, and a 3D-printed enclosure.
</p>

<h1 align="center">Overview</h1>
        
<p align="center">Luna is a DIY Tamagotchi that lives inside a tiny OLED screen. Powered by the incredibly compact XIAO ESP32C3 microcontroller, it features 4 tactile buttons and a rotary encoder to interact with your pet. You can feed it Luosifen, take it mountain climbing, let it nap, or play a wildcard minigame to keep its stats high!

<h1 align="center">Why am I even building this?</h1>
<p align="center">
 This project was inspired by classic virtual pets and serves as an awesome way to learn about simple game loops, I2C displays, debouncing buttons, and generating graphics in C++. A huge shoutout and <strong>credit to Hack Club Fallout's Tamagotchi guide</strong> for providing the inspiration and foundation for this build!
 </p>

<h1 align="center">The Features</h1>
</div>

1. **Virtual Pet Ecosystem**: Monitor four core stats—Hunger, Happiness, Energy, and Intelligence. If any stat drops too low, your pet gets sad!
2. **Interactive Activities**: 
   - **Feed (Luosifen)**: Restores hunger and gives a little energy.
   - **Play (Climb Mountain)**: Boosts happiness but drains energy.
   - **Sleep (Nap)**: Heavily restores energy and boosts intelligence.
3. **Wildcard Minigame**: Use the rotary encoder to guess a random number between 0 and 20. Guess correctly (or within 1 number) and happiness is doubled! Fail, and happiness decreases by 15%.
4. **Dynamic OLED Graphics**: Features custom bitmap sprites that change expressions (Happy, Neutral, Sad) based on the pet's current state.

<div align="center">   
 
# Repository Contents

| Path | What it contains |
| --- | --- |
| `BOM` | Bill of materials details and cost breakdowns |
| `FIRMWARE` | The main Arduino C++ code (`firmware.ino`) handling the game loop and display graphics |
| `IMAGES` | Zine scans, screenshots, and visual documentation |

</div>

# The Components Used

1. Seeed Studio XIAO ESP32C3
2. 0.96-inch OLED Display (I2C Interface, SSD1306)
3. 5V Active Electromagnetic Buzzer
4. 12mm x 12mm Tactile Switches (x4)
5. Rotary Encoder (KY-040 or similar)
6. Custom PCB
7. Custom 3D Printed Case

# Bill of Materials

| Component Name | Link | Total Cost (₹) |
| --- | --- | --- |
| XIAO ESP 32 C3 | [Seeed Studio](https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html) | ₹650 |
| 0.96 OLED DISPLAY | [Quartz Components](https://quartzcomponents.com/products/oled-display-0-96-inch-i2c-interface-4-pin-blue-ssd1306) | ₹138 |
| BUZZER | [Robu.in](https://robu.in/product/5v-active-electromagnetic-buzzer-pack-of-5/) | ₹16 |
| 12MM*12MM TACTILE SWITCHES | [Robu.in](https://robu.in/product/tsf001b12018a-bzcn-12mm-12mm-50ma-round-button-direct-insert-12mm-180gf-12v-plugin-tactile-switches-rohs/) | ₹5 |
| Custom PCB | [JLCPCB](https://cart.jlcpcb.com/) | ₹945 |
| 3D PRINTS | [Dwart Industries](https://dwartindustries.com/shop/additive-manufacturing/fdm-3d-printing-services/) | ₹411 |
| **Subtotal** | | **₹2165** |

#  Schematic
<img width="2032" height="1242" alt="Screenshot 2026-06-21 122848" src="https://github.com/user-attachments/assets/66084597-d61b-45fa-939b-7a57bd0637e6" />



# How to Build it?

**To replicate, follow the steps below:**
1) Send the custom PCB gerbers to JLCPCB.
2) 3D print the case enclosure using FDM.
3) Gather all the components listed in the BOM.
4) Solder the XIAO ESP32C3, OLED display, buttons, buzzer, and rotary encoder onto the custom PCB.
5) Flash the provided `firmware.ino` using the Arduino IDE.
6) Assemble the PCB into the 3D printed shell.
7) Power it on and start taking care of Luna!

## Firmware setup
 - Connect your XIAO ESP32C3 to your computer.
 - Install the **ESP32 Board Package** in the Arduino IDE and select `XIAO_ESP32C3`.
 - Install the **Adafruit GFX** and **Adafruit SSD1306** libraries via the Library Manager.
 - Compile and upload `firmware.ino` to the board.
 
<h1>Inspirations & Credits</h1> 
Huge thanks to the <strong>Fallout Hack Club Tamagotchi guide</strong> for the base inspiration and logic outline.
