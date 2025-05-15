#include <arduino.h>
#include <config.h>
#include "claves.h"
#include <WiFi.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme; // I2C


// -------------------------------------------------------------------------
// Declaración de Configuración del Setup
int configuracionSetup(){

    uint8_t errorCode = 0;

    // CONFIGURACIÓN DE MONITOR SERIAL
    Serial.begin(115200);
    
    // CONEXIÓN DEL WIFI
    WiFi.begin(wifiSSID, wifiPass);

    Serial.println("[WiFi] WiFi is connected!");
    Serial.print("[WiFi] IP address: ");
    Serial.println(WiFi.localIP());

    // SENSOR HUMEDAD BME280

    Serial.begin(9600);
    while (!Serial); // Espera si es necesario

    if (!bme.begin(0x76)) { // Algunos módulos usan 0x77
        Serial.println("¡No se encontró el sensor BME280!");
        while (1);
    }

return errorCode;
}


//-------------------------------------------------------------------------
// CÓDIGO PARA EL SETUP DE PRUEBAS
int configuracionSetupTest(){
    uint8_t errorCode = 0;

    

    return errorCode;
}