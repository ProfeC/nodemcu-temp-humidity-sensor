// // Libraries
// #include "Arduino.h"
// // #include <Adafruit_HDC1000.h>
// // Adafruit_HDC1000 hdc = Adafruit_HDC1000(); // Create a class for the HDC Sensor

// float getTempCelsius(void) {
//   return hdc.readTemperature();
// }

// float getTempFahrenheit(void) {
//   float currentTemp = hdc.readTemperature();
//   return currentTemp * 9/5 + 32;
// }

// float getTempKelvin(void) {
//   float currentTemp = hdc.readTemperature();
//   return currentTemp + 273.15;
// }

// // void handleTemperature() {
// //   String json = "";
// //   json += "{\"temperature\":{\"celsius\":";
// //   json += getTempCelsius();
// //   json += ",\"fahrenheit\":";
// //   json += getTempFahrenheit();
// //   json += ",\"kelvin\":";
// //   json += getTempKelvin();
// //   json += "}}";
// //   server.send ( 200, "application/json", json );
// //   json = String();
// // }

// // void handleTemperatureC() {
// //   String json = "";
// //   json += "{\"temperature\":{\"celsius\":";
// //   json += getTempCelsius();
// //   json += "}}";
// //   server.send ( 200, "application/json", json );
// // }

// // void handleTemperatureF() {
// //   String json = "";
// //   json += "{\"temperature\":{\"fahrenheit\":";
// //   json += getTempFahrenheit();
// //   json += "}}";
// //   server.send ( 200, "application/json", json );
// // }

// // void handleTemperatureK() {
// //   String json = "";
// //   json += "{\"temperature\":{\"kelvin\":";
// //   json += getTempKelvin();
// //   json += "}}";
// //   server.send ( 200, "application/json", json );
// // }
