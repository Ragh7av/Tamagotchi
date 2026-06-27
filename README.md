 <h1 align="center">Tamagotchi</h1>
 <img width="1175" height="648" alt="Screenshot 2026-06-23 235815" src="https://github.com/user-attachments/assets/d0b50554-49d4-47b8-b4b8-e9aa9b47dddf" />


<div align="center">         
<p align="center">
Super smol tamagotchi pet for you!
</p>

<h1 align="center">Overview</h1>
        
<p align="center">
 
 Custom tamagotchi with a super small formfactor and can help you [larp](https://en.wiktionary.org/wiki/LARP) building hardware. Made using the good old ESP32 C3 Supermini, an 0.96 oled panel, three [smol](https://en.wiktionary.org/wiki/smol) tactile switches, buzzer, and a battery [ofc](https://en.wikipedia.org/wiki/OFC) with a custom PCB and a 3D printed case! 

 [Onshape 3D Model link](https://cad.onshape.com/documents/aaa376a98daf92ea29d656f5/w/34884ae89482b25306f22cdd/e/82753004b14a47683b19c43f)


 #  Schematic
<img width="1209" height="772" alt="Screenshot 2026-06-22 183809" src="https://github.com/user-attachments/assets/02815ffc-1aa8-4366-a8eb-51954e0f9ee3" />


# Printed Circuit Board (PCB)
<img width="982" height="746" alt="Screenshot 2026-06-25 202214" src="https://github.com/user-attachments/assets/c77addca-64c1-4212-a41f-e1f42d21dba9" />

<img width="938" height="1119" alt="Screenshot 2026-06-25 175817" src="https://github.com/user-attachments/assets/89f8a3b3-8824-4689-90b8-ac6bcd631b77" />
<img width="765" height="1226" alt="Screenshot 2026-06-23 164353" src="https://github.com/user-attachments/assets/5531e6e4-834f-4e68-bdf5-7c9793a11cb0" />

# 3D MODEL OF ASSEMBLY
<img width="1175" height="648" alt="Screenshot 2026-06-23 235815" src="https://github.com/user-attachments/assets/8c2e6c43-a40e-44c3-98a0-bffa34876ad0" />
<img width="1155" height="748" alt="Screenshot 2026-06-23 235724" src="https://github.com/user-attachments/assets/12c7a8a6-53df-46d8-b238-f051e6bc723e" />
<img width="1192" height="1034" alt="Screenshot 2026-06-23 234828" src="https://github.com/user-attachments/assets/d846138c-035a-4c91-a216-5f8685018b35" />
<img width="1157" height="751" alt="Screenshot 2026-06-23 235446" src="https://github.com/user-attachments/assets/beb4017c-5b29-4b6a-a178-0c389ba30161" />

# ZINE

<img width="972" height="1498" alt="Zine-Tamagotchi" src="https://github.com/user-attachments/assets/88dae22f-f768-49cf-9d26-f4c5064aa491" />


<h1 align="center">Why did I even build this?</h1>
<p align="center">
 
 to [larp](https://en.wiktionary.org/wiki/LARP) as a super smol cyberpet is cool [asf](https://en.wikipedia.org/wiki/Autism_Science_Foundation). 
 
 </p>

<h1 align="center">The Features</h1>
</div>


**Feeding:** Fills the hunger meter (much like a crunchy kfc) with sound effects

**Playing:**Yooo... Pauses the normal world to launch the falling-item arcade game. Catching items makes the pet superrrr happy but sadlyy acts as a 20% battery tax on its energy.

**Sleeping:** Dims the screen into a snoozee/ sleeping mode, locking the controls until its energy battery safely recharges back to 100% and get's into full powerr.

# The Components Used

1. ESP32 C3 supermini.
2. 0.96-inch OLED Display (SSD1306)
3. smol Buzzer.
4. 6mm x 6mm x 8mm Tactile Switches (x3).
5. Battery
7. Custom designes PCB.
8. Custom 3D Printed Case.

# How to Build it?
## 1. Project Files and Parts
Download the necessary files from this repository:
* Gerbers: For ordering the custom PCB.
* 3D Prints: For printing the outer case.
* Firmware: For the Arduino source code.

Now collect all the hardware components. You will need an ESP32-C3 Supermini, a 0.96-inch I2C OLED display, three 6mm tactile switches, a buzzer and a battery cell.
## 2. Hardware Assembly

To assemble the hardware follow these steps:
1. Solder the ESP32-C3 Supermini onto the designated footprint on your PCB.
2. Next solder the three switches into positions SW4, SW5 and SW6.
3. Then solder the OLED display into the U2 slot.
4. After that solder the buzzer to the BZ1 pads.
5. Solder the battery wires to the BT1 power pads. It is very important to check the schematic to ensure the positive and negative match exactly to prevent shorting out the ESP32-C3 Supermini board.
6. Finally, Place the PCB in the 3D printed bottom case and screw it to the case.

## 3. Software Environment Setup

To set up the software environment follow these steps:

1. Install the Arduino IDE on your computer.
3. Go to File then Preferences. Add the official ESP32 library URL to the Additional Boards Manager URLs box.
5. Open Tools, Board then Boards Manager, search for ESP32 by Expressif and click install.
6. Go back to Tools, Board, then ESP32 Arduino and select ESP32 C3 Dev Module.

## 4. Library Installation and Flashing

To install the library and flash the firmware follow these steps:

1. Go to Sketch Include Library then Manage Libraries.
2. Search for Adafruit SSD1306. Click install. Select "Install All" to include the required Adafruit GFX dependency.
3. Open your project firmware file in the Arduino IDE.
4. Connect the ESP32-C3 Supermini device to your computer using a data cable.
5. Select the devices connection port, under Tools, Port.
6. Click the Upload button. The OLED screen will boot up with the system text soon as the terminal finishes writing the code to the ESP32-C3 Supermini.
   
<h1>Inspirations & Credits</h1> 
Huge thanks to the <strong>Fallout Hack Club Tamagotchi guide</strong> for the base inspiration and logic outline.

