# ParkingInformationSystem

# Arduino Project Development Framework

[![Documentation Status](https://www.arduino.cc/en/Main/Software)

ARDUINO is the official development framework for the [Arduino Uno](https://www.arduino.cc/en/Tutorial/HomePage).

# Developing With ARDUINO UNO

## Setting Up ARDUINO FRAMEWORK

See setup guides for detailed instructions to set up the ARDUINO:

* [Getting Started Guide for the Arduino](https://www.arduino.cc/)

## Finding a Project

Clone the project, and open the project in Arduino Framework.

Once you've found the project you want to work with, change to its directory and you can configure and build it.

To start your own project based on an example, copy the example project directory.


## Configuring the Project

`make menuconfig`

* Opens Tools, change Board name; ESP12E.
* change Port name.

## Compiling the Project

`compile`

... will compile app, bootloader and generate a partition table based on the config.


## Flashing/Uploading the Project

When the build finishes, it will print a command line to use esptool.py to flash the chip. However you can also do this automatically by running:

`Upload`

This will upload the entire project (app, bootloader and partition table) to a . The settings for serial port flashing can be default configured.


## Viewing Serial Monitor

On click on Serial Monitor, you can see the parking slots is available of not by the distance given by the Ultrasonic sensor.
```
Serial Monitor
```


## The Parking Slots

When the person entering parking area can view the parking website, if parking is vacant then he/she will online pay for parking slot, then enter into parking lot and park its vehicle. Website will indicate directly which parking slot is vacant in any lane. Empty slot is indicated by Green and occupied slot is indicated by Red.

## Website

The `http://parkinginfo.000webhostapp.com/` target the information of each slots of the parking system. However it is sometimes useful to select your parking slot, and book for a particular time.

This can be combined with CCTV cameras and integration of Boom Barrier, ie for security purpose. Using CCTV cameras security, of the parking area can be enhanced.

