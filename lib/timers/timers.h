

// DEFINICIONES
#define t_Base 0

// ----------- CONFIG DE TIMERS -----------
// uint32_t millisActual = 0; // No es necesario aquí si ya está en el .ino

// Tiempo de escaneo de red Wifi
unsigned long t_WifiScan_prev = 0;
const int t_WifiScan_i = 5000;

unsigned long t_WifiReconnect_prev = 0; // Nuevo timer para el intento de reconexión
const int t_WifiReconnect_i = 10000;

// Tiempo para mostrar IP después de conectar
unsigned long t_WifiShowIp_prev = 0;
const int t_WifiShowIp_i = 500;