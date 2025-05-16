#include <Arduino.h>
#include <WiFi.h>

// Bibliotecas internas
#include "botones.h"
#include "claves.h"
#include "timers.h"
#include "config-main.h"
#include "config-test.h"

// Bilioteca i2c
#include <SPI.h>
#include <Wire.h>

// Display SSD1306
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Sensor BME280
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme; // I2C

bool testMode = 0;

void setup() {
    
    // FUNCIONES POR DEFECTO
    if (!testMode) {
        configuracionSetup();
    } else {
        configuracionSetupTest();    // CODIGO DE PRUEBA
    }
        
}

void loop(){

    // FUNCIONES POR DEFECTO
    if (!testMode) {
        configuracionLoop();
    } else {    
        configuracionLoopTest();    // CODIGO DE PRUEBA
    }

    // Serial.print("Temperatura = ");
    // Serial.print(bme.readTemperature());
    // Serial.println(" *C");

    // Serial.print("Presión = ");
    // Serial.print(bme.readPressure() / 100.0F);
    // Serial.println(" hPa");

    // Serial.print("Humedad = ");
    // Serial.print(bme.readHumidity());
    // Serial.println(" %");

    // Serial.print("Altitud aproximada = ");
    // Serial.print(bme.readAltitude(1013.25)); // Ajusta según tu presión local
    // Serial.println(" m");

    // Serial.println();
    // delay(2000);

}
