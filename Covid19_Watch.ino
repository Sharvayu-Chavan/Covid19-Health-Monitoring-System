#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define wifi_ssid "DPSPCN"
#define wifi_password "sharvayu@25"

#define mqtt_server "techpradnya.in" //"m23.cloudmqtt.com"
#define mqttUser "techpradnya"//"nrxyvxfh"
#define mqttPassword "techpradnya"//"pBqLKJYPlGiV"

#include <Wire.h>
#include <MAX30105.h>
#include <Ticker.h>  //Ticker Library
Ticker blinker;
#include "heartRate.h"

MAX30105 particleSensor;

const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
float beatsPerMinute;
int beatAvg;
float vref = 3.3;
float resolution = vref / 1023;


WiFiClient espClient;
PubSubClient client(espClient);


void setup()
{
  Serial.begin(115200);
  blinker.attach(0.5, changeState); 
  Serial.println("Initializing...");
  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  client.setServer(mqtt_server, 8883);
  //client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }

    // Initialize sensor
    if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
    {
      Serial.println("MAX30105 was not found. Please check wiring/power. ");
      while (1);
    }
    Serial.println("Place your index finger on the sensor with steady pressure.");

    particleSensor.setup(); //Configure sensor with default settings
    particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
    particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
    
  }
}

void loop()
{
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }

  }

  Serial.print("IR=");
  Serial.print(irValue);
  Serial.print(", BPM=");
  Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);

  float temperature = analogRead(A0);
  temperature = (temperature * resolution);
  temperature = temperature * 100;
  temperature = (1.8 * temperature) + 32;
  Serial.print(", Avg Temperature =");
  Serial.print(temperature);


  if (irValue < 50000)
    Serial.print(" No finger?");

  Serial.println();
  
}
void changeState()
{
  client.publish("BPM", "Complete");
}
