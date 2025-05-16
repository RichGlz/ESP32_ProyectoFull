// Bibliotecas generales
#include <Arduino.h>
#include <WiFi.h>

// // Bibliotecas internas
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

unsigned long millisActual = millis();

unsigned long t_WifiScan_prev;
unsigned long t_WifiScan_i;

// Tiempo para reconectar Wifi
unsigned long t_WifiReconnect_prev;
unsigned long t_WifiReconnect_i;

// Tiempo para mostrar IP después de conectar
unsigned long t_WifiShowIp_prev;
unsigned long t_WifiShowIp_i;

// Declaramos las variables globales que vienen de timers.h
// unsigned long millisActual = 0;


// -------------------------------------------------------------------------
// Declaración de Configuración del Setup
void configuracionSetup(){
 unsigned int errorCode = 0;

    // CONFIGURACIÓN DE MONITOR SERIAL
    Serial.begin(115200);
    
    // CONEXIÓN DEL WIFI
    WiFi.begin(wifiSSID, wifiPass);

    Serial.println("[WiFi] WiFi is connected!");
    Serial.print("[WiFi] IP address: ");
    Serial.println(WiFi.localIP());


    

    // SENSOR HUMEDAD BME280

    //    Serial.begin(9600);
    // while (!Serial); // Espera si es necesario

    // if (!bme.begin(0x76)) { // Algunos módulos usan 0x77
    //     Serial.println("¡No se encontró el sensor BME280!");
    //     while (1);
    // }

    // -------------------------------------------------------------------------
    // -------------------------------- SSD1306 --------------------------------
    // -------------------------------------------------------------------------

    #define _displayAncho 128   // ANCHO del display OLED en pixeles
    #define _displayAlto 64     // ALTO del display OLED en pixeles
    #define OLED_RESET -1       // # Pin de Reset (o -1 si se comparte el pin de reset del Arduino)
    #define SCREEN_ADDRESS 0x3C // mira el datasheet Para la dirección; puede ser 0x3C o 0x3D.

    uint8_t _ancho = 128-1;
    uint8_t _alto = 64-1;

    Adafruit_SSD1306 display(_displayAncho, _displayAlto, &Wire, OLED_RESET);

    // SSD1306_SWITCHCAPVCC = configura el voltaje del display a 3.3V de manera interna.
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("No se encontró al SSD1306"));
        for(;;); // Bucle infinito. No avanzará si esto pasa.
    }

    // Limpia el buffer.
    display.clearDisplay();

    // Se agrega al buffer líneas horizontales en color blanco.
    display.drawLine(0, 0,128, 0, WHITE); // Línea horizontal, con Y =  0
    display.drawLine(0,15,128,15, WHITE); // Línea horizontal, con Y = 15
    display.drawLine(0,16,128,16, WHITE); // Línea horizontal, con Y = 16
    display.drawLine(0,63,128,63, WHITE); // Línea horizontal, con Y = 63

    // Se agrega al buffer las letras "Geeksium".
    display.setTextColor(WHITE);          // Se configura el color comoblanco
    display.setTextSize(1);               // Tamaño del texto (del 1 al 6).
    display.setCursor(42, 4);             // Se pone el cursor en la posición x=42, y=4.
    display.println("Geeksium");          // Se imprime la cadena "Geeksium".

    // Muestra el buffer de la pantalla. Tienes que invocar la función "display()"
    // después para hacer los elementos visibles en la pantalla.
    display.display();
    delay(2000);
    // display.display() NO es necesario que se ponga en en cada línea
    // a menos que sea lo que quieras, de otra manera haz al configuración
    // y ejecuta la función "display.display()" al final.



// return errorCode;
}


// -------------------------------------------------------------------------
// Declaración de Configuración del Loop
void configuracionLoop(){
    
unsigned int errorCode = 0;


    // Verificar y reconectar WiFi periódicamente
    if (WiFi.status() != WL_CONNECTED) {
        if (millisActual - t_WifiReconnect_prev >= t_WifiReconnect_i) {
            Serial.println("[WiFi] Conexión perdida. Intentando reconectar...");
            WiFi.begin(wifiSSID, wifiPass);
            t_WifiReconnect_prev = millisActual; // Actualizamos el timer de reintento
        }
        delay(10);
    } else {
        if (millisActual - t_WifiScan_prev >= t_WifiScan_i) {
            t_WifiScan_prev = millisActual;
        }
    }
    
//return errorCode;
}