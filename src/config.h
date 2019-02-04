#include "creds.h"

/******************************* WIFI **************************************/

// the AdafruitIO_WiFi client will work with the following boards:
//   - HUZZAH ESP8266 Breakout -> https://www.adafruit.com/products/2471
//   - Feather HUZZAH ESP8266 -> https://www.adafruit.com/products/2821
//   - Feather HUZZAH ESP32 -> https://www.adafruit.com/product/3405
//   - Feather M0 WiFi -> https://www.adafruit.com/products/3010
//   - Feather WICED -> https://www.adafruit.com/products/3056


// comment out the following two lines if you are using fona or ethernet
#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

/**************************** DEFAULTS ************************************/

#define LED_RED D1
#define LED_GREEN D2
#define LED_BLUE D3
#define TEMPERATURE_CLOCK D5
#define TEMPERATURE_DATA D4

// NOTE: Temperature reference found at https://www.gmp-compliance.org/gmp-news/what-are-the-regulatory-definitions-for-ambient-room-temperature-and-cold-chain
#define TEMPERATURE_LOW 20 // 68F
#define TEMPEATURE_HIGH 25 // 77F

#define RELATIVE_HUMIDITY_HIGH 60
#define RELATIVE_HUMIDITY_LOW 30