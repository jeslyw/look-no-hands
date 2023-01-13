# Bluetooth page turner

Adapted from Joonas Pihlajamaa's DIY bluetooth pedal and [ESP32 Ble Keyboard library](https://github.com/T-vK/ESP32-BLE-Keyboard) sample code 

Turns a pedal + ESP32 combo into a bluetooth page turner

This code works with a pedal or button controller:<br>
Single press -> next page / right keyboard arrow<br> 
Long press -> previous page / left keyboard arrow 

## App compatibility

Works with any app that supports keyboard l-r function 

## Hardware
<ul>
<li>ESP32 board</li> 
<li>Foot pedal/button</li> 
</ul>
For initial testing/prototyping, a breadboard setup with push button and jumper wires is recommended<br>
This allows for experimentation with different input pins and wiring points<br>
Connection points: input and ground pins 

## Setup

Make sure  `Serial.begin(115200)` is set to `monitor_speed` found in project configuration file for your board 

## Input Pin 

D13 used (located next to GND on the NodeMCU-ESP32), but can be adapted by replacing 13 in `#define inputPin 13` with chosen pin 

## Pedal Sensitivity

Touch can be adjusted by altering `heldFor < 50000`<br><br>
Increasing count will prolong the heldfor time required to return to previous page 






