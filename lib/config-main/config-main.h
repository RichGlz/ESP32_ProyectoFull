#ifndef CONFIG_MAIN_H
#define CONFIG_MAIN_H

#include <Arduino.h>
#include <WiFi.h>

// Bibliotecas internas
#include "claves.h"
#include "timers.h"
#include "config-main.h"

// Bilioteca i2c
#include <SPI.h>
#include <Wire.h>

// Display SSD1306
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Sensor BME280
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>


// Declaración de funciones
    void configuracionSetup();
    void configuracionLoop();

#endif // CONFIG_MAIN_H
