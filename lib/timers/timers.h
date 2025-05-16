#ifndef TIMERS_H
#define TIMERS_H

extern unsigned long millisActual;

extern unsigned long t_WifiScan_prev;
extern unsigned long t_WifiScan_i;

// Tiempo para reconectar Wifi
extern unsigned long t_WifiReconnect_prev;
extern unsigned long t_WifiReconnect_i;

// Tiempo para mostrar IP después de conectar
extern unsigned long t_WifiShowIp_prev;
extern unsigned long t_WifiShowIp_i;

#endif
