
 
 
 <h1 align="center">Tamagotchi</h1>
 <img width="1175" height="648" alt="Screenshot 2026-06-23 235815" src="https://github.com/user-attachments/assets/d0b50554-49d4-47b8-b4b8-e9aa9b47dddf" />


<div align="center">         
<p align="center">
Super smol tamagotchi pet for you!
</p>

<h1 align="center">Overview</h1>
        
<p align="center">
 
 Custom tamagotchi with a super small formfactor and can help you [larp](https://en.wiktionary.org/wiki/LARP) building hardware. Made using the good old ESP32 C3 Supermini, an 0.96 oled panel, three [smol](https://en.wiktionary.org/wiki/smol) tactile switches, buzzer, and a battery [ofc](https://en.wikipedia.org/wiki/OFC) with a custom PCB and a 3D printed case!

 #  Schematic
<img width="1209" height="772" alt="Screenshot 2026-06-22 183809" src="https://github.com/user-attachments/assets/02815ffc-1aa8-4366-a8eb-51954e0f9ee3" />


# Printed Circuit Board (PCB)
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


**Feeding:** Instantly fills the hunger meter and plays a quick "crunch" sound.

**Playing:** Pauses the normal world to launch the falling-item arcade game. Catching items makes the pet happy but acts as a 20% battery tax on its energy.

**Sleeping:** Dims the screen into a snooze mode, locking the controls until its energy battery safely recharges back to 100%.
<div align="center">   
 
# Repository Contents

| Path | What it contains |
| --- | --- |
| `BOM` | Bill of materials details and cost breakdowns |
| `FIRMWARE` | The main Arduino C++ code (`firmware.ino`) handling the game loop and display graphics |
| `IMAGES` | Zine scans, screenshots, and visual documentation |
| `IMAGES` | Zine scans, screenshots, and visual documentation |
| `IMAGES` | Zine scans, screenshots, and visual documentation |
| `IMAGES` | Zine scans, screenshots, and visual documentation |
| `IMAGES` | Zine scans, screenshots, and visual documentation |

</div>

# The Components Used

1. ESP32 C3 supermini
2. 0.96-inch OLED Display (SSD1306)
3. smol Buzzer
4. 6mm x 6mm x 8mm Tactile Switches (x3)
5. Battery
7. Custom PCB
8. Custom 3D Printed Case

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
https://cad.onshape.com/documents/aaa376a98daf92ea29d656f5/w/34884ae89482b25306f22cdd/e/82753004b14a47683b19c43f?renderMode=0&uiState=6a3ace564e6c75de72ba1469
