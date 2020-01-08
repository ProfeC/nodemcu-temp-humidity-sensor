#include <Arduino.h>
#include <Adafruit_HDC1000.h>
#include <Adafruit_Sensor.h>
#include "config.h"

Adafruit_HDC1000 hdc = Adafruit_HDC1000(); // Create a class for the HDC Sensor

const int hdc_sda = TEMPERATURE_DATA; // SDA port for the HDC1000
const int hdc_scl = TEMPERATURE_CLOCK; // SCL port for the HDC1000
const int ledWiFi = D0; // LEDs are going to be used.
// const char chipID = ESP.getChipId(); // The ESP's Chip ID
// const char *dnsName = "webdev-esp8266-" + chipID; // DNS Name
const char* strTemp = "Current temp is: ";
const char* strHum = "Current humidity is: ";
const int checkEvery = 90; // number of seconds between each temp check.
// const int roomTempHigh = 74; // Standart room temp in fahrenheight
// const int roomTempLow = 68; // Standart room temp in fahrenheight

// FUNCTIONS
// void handleTemperature();
// void handleTemperatureC();
// void handleTemperatureF();
// void handleTemperatureK();
// void handleHumidity();
float getHumidityRH(void);
float getTempFahrenheit(void);
float getTempCelsius(void);
void updateLED(int red, int blue, int green);

// set up the 'temperature' and 'humidity' feeds
AdafruitIO_Feed *temperaturec = io.feed("temperature-c");
AdafruitIO_Feed *temperaturef = io.feed("temperature-f");
AdafruitIO_Feed *humidity = io.feed("humidity");

void setup() {
	// Set up serial monitor
	Serial.begin(115200);

	// Serial.print('Chip ID = ' + chipID);
	// Serial.println('====');
	// Serial.println('DNS Name = ' + dnsName);

	// Turn off LED
	updateLED(1023, 1023, 1023);

	// Start sensors
	hdc.begin();

	Serial.println("\nSetting up HDC100x...");
	Wire.begin(TEMPERATURE_DATA, TEMPERATURE_CLOCK);
	if (!hdc.begin()) {
		Serial.println("\nCouldn't find sensor!");
	while (1);
	}

	// connect to io.adafruit.com
	Serial.print("Connecting to Adafruit IO");
	// io.connect();

	// wait for a connection
	while(io.status() < AIO_CONNECTED) {
		Serial.println(io.statusText());
		delay(500);
	}

	// we are connected
	Serial.println();
	Serial.println(io.statusText());
}

void loop() {
	// put your main code here, to run repeatedly:
	io.run();

	const float currentTempF = getTempFahrenheit();
	const float currentTempC = getTempCelsius();
	const float currentHumidity = getHumidityRH();

	// save fahrenheit (or celsius) to Adafruit IO
	temperaturef->save(currentTempF);
	temperaturec->save(currentTempC);

	// save humidity to Adafruit IO
	humidity->save(currentHumidity);

	if (currentTempC > TEMPEATURE_HIGH ) {
		updateLED(0, 1000, 1000);
	}

	if (currentTempC < TEMPEATURE_HIGH && currentTempC > TEMPERATURE_LOW ) {
		updateLED(1023, 768, 0);
	}

	if (currentTempC < TEMPERATURE_LOW) {
		updateLED(1023, 0, 1023);
	}

	Serial.print(strTemp); Serial.println(getTempFahrenheit());
	Serial.print(strHum); Serial.println(currentHumidity);
	delay(checkEvery * 1000);
}

float getTempCelsius(void) {
  return hdc.readTemperature();
}

float getTempFahrenheit(void) {
  float currentTemp = hdc.readTemperature();
  return currentTemp * 9/5 + 32;
}

float getTempKelvin(void) {
  float currentTemp = hdc.readTemperature();
  return currentTemp + 273.15;
}

float getHumidityRH(void) {
	return hdc.readHumidity();
}

void updateLED(int red, int blue, int green) {
	analogWrite(LED_RED, red);
	analogWrite(LED_BLUE, blue);
	analogWrite(LED_GREEN, green);
}
