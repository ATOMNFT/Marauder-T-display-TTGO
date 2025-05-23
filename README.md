![Header](Images/mainheader.png)
<br>

<div align="center" style="max-width: 100%; overflow: visible;">
  <img 
    src="https://github.com/ATOMNFT/Marauder-T-display-TTGO/blob/main/Images/Repolike.svg" 
    style="width: 100%; height: 110px; max-width: 800px;" 
    alt="Responsive SVG">
</div>

<div align="left">


## ⬆ TTGO T-Display 1.14in Update Highlights 5/7/25 ⬆ <br> Added New v1.4.6!
  


---

📡 TTGO T-Display WiFi Marauder Fork 🚀
A stunning fork of the WiFi Marauder suite, optimized for the TTGO T-Display!
This version introduces exciting new features, bug fixes, and customizations for WiFi/Bluetooth offensive and defensive tasks. Perfect for hobbyists and security enthusiasts!
<br>
Take your TTGO T-Display to the next level with these powerful updates! Contributions and feedback are welcome. 🎉

---

# 📚 Libraries 📚
You MUST install this version of NimBLE <a href=https://github.com/h2zero/NimBLE-Arduino/releases/tag/1.3.5>NimBLE 1.3.5</a>
<br>
The other libraries needed can be located <a href=https://github.com/justcallmekoko/ESP32Marauder/wiki/installing-firmware-from-source#installing-firmware-from-source>HERE</a> 

---

# ⚙️ User_Setup Files ⚙️
<a href=https://github.com/ATOMNFT/Marauder-T-display-TTGO/tree/main/User_Setups>THESE</a> files are to be placed in the TFT_eSPI library folder if you plan to compile from the sketch files.
<br> 
Make sure to back up your TFT_eSPI lib folder prior to replacing these files.

---

# SD Wiring Diagram
Here is a simple pic to explain wiring up a micro SD module.
![T-display-SD-Pin](Images/T-display-SD-Pin.png)

# 🛠️ **SD Portal fix (Only in 1.2.0)**

  ### Adjusted sd card portal storage
  <b>I have tweaked a section of two files (EvilPortal.cpp & SDInterface.h) to allow the portals used in EP to be stored in a folder on the sd card instead of just being stored in the root of sd card
  along with all the pcaps and other files captured.</b>
  
  ### SD Setup for T-Display
  If you flashed from the <a href=https://atomnft.github.io/Marauder-T-display-TTGO/flash0.html>Marauder T-display flash tool</a> or built from <a href=https://github.com/ATOMNFT/Marauder-T-display-TTGO>Marauder T-display</a> then you must create a folder titled "portals" or drop the "portals" folder in this repo on the root of your sd card after unzipping it.
  
  <br>
 
  <b>The folder titled "portals is to be added to the root of your sd card. It contains the ap.config file, a file titled "index.html", and a few smaller sized portals. Download the 7z file and unzip it. Drag or copy/paste the folder titled "portals" to the root of your sd card. </b>
  
  <br>
  
  <b>The sd adjustment/fix is already included in <a href=https://github.com/ATOMNFT/Marauder-T-display-TTGO> this sketch for the T-Display.</a>  if you plan to build from source</b>

<hr>

> # 🛠️ **Device Compatibility**
> 
> Successfully tested on:
> - [T-display variant 1](https://a.co/d/aH2SvRw)  
> - [T-display variant 2](https://a.co/d/eFvFgLy)  

<hr>

# ⚡ **Web Flasher**
Use the link below to flash with the new web flasher tool!
<br>
<a href=https://atomnft.github.io/Marauder-T-display-TTGO/flash0.html>Web Flasher Tool</a>

</div>

---
<details>
<summary><h2>ESP32 Marauder Info</h2></summary>

# ESP32 Marauder
<p align="center"><img alt="Marauder logo" src="https://github.com/justcallmekoko/ESP32Marauder/blob/master/pictures/marauder3L.jpg?raw=true" width="300"></p>
<p align="center">
  <b>A suite of WiFi/Bluetooth offensive and defensive tools for the ESP32</b>
  <br><br>
  <a href="https://github.com/justcallmekoko/ESP32Marauder/blob/master/LICENSE"><img alt="License" src="https://img.shields.io/github/license/mashape/apistatus.svg"></a>
  <a href="https://gitter.im/justcallmekoko/ESP32Marauder"><img alt="Gitter" src="https://badges.gitter.im/justcallmekoko/ESP32Marauder.png"/></a>
  <a href="https://github.com/justcallmekoko/ESP32Marauder/releases/latest"><img src="https://img.shields.io/github/downloads/justcallmekoko/ESP32Marauder/total" alt="Downloads"/></a>
  <br>
  <a href="https://twitter.com/intent/follow?screen_name=jcmkyoutube"><img src="https://img.shields.io/twitter/follow/jcmkyoutube?style=social&logo=twitter" alt="Twitter"></a>
  <a href="https://www.instagram.com/just.call.me.koko"><img src="https://img.shields.io/badge/Follow%20Me-Instagram-orange" alt="Instagram"/></a>
  <br><br>
  <a href="https://www.tindie.com/products/justcallmekoko/esp32-marauder/"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-larges.png" alt="I sell on Tindie" width="200" height="104"></a>
  <br>
  <a href="https://www.twitch.tv/willstunforfood"><img src="https://assets.stickpng.com/images/580b57fcd9996e24bc43c540.png" alt="Twitch WillStunForFood" width="200"></a>
</p>
    
# Getting Started
Download the [latest release](https://github.com/justcallmekoko/ESP32Marauder/releases/latest) of the firmware.  

Check out the project [wiki](https://github.com/justcallmekoko/ESP32Marauder/wiki) for a full overview of the ESP32 Marauder

# For Sale Now
You can buy the ESP32 Marauder using [this link](https://www.tindie.com/products/justcallmekoko/esp32-marauder/)

</details>
