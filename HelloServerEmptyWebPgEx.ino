#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "homepage.h"
#include <DFRobot_DHT11.h>
#include <HCSR04.h>
#include "ThingSpeak.h"
#include "secrets.h"
DFRobot_DHT11 DHT;
#define DHT11_PIN 4
//ultrasonic pins
#define trigPin 5
#define echoPin 17
//pirastatic pump
#define PERI_MOTOR 23
//to get soil
const int WateredsoilValue = 2350;  // You need to change this value that you had recorded in the wate
int soilMoistureValue = 0;


char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0; 
WiFiClient  client;
WebServer server(80);

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;


void handleRoot() {
  String temperature = getTemp();
  String humidity = getHumi();
  String waterLevel = getwaterlevel();
  String Soil = getwateringsystem();

  String message = homePagePart1 + temperature + homePagePart2 + humidity + homePagePart3 + waterLevel + homePagePart4 + Soil + homePagePart5;
  server.send(200, "text/html", message);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

// Initialize our values
int TempC = 0;
int Humidity = 0;
int WaterLevel = 0;
String myStatus = "";

void setup(void) {
  Serial.begin(115200);
  pinMode(PERI_MOTOR, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  WiFi.mode(WIFI_STA);  
  ThingSpeak.begin(client);
  WiFi.begin(SECRET_SSID, SECRET_PASS);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
   // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
  server.handleClient();
  delay(2);  // Allow the CPU to switch to other tasks

  // set the fields with the values
  ThingSpeak.setField(1, getTemp());
  ThingSpeak.setField(2, getHumi());
  ThingSpeak.setField(3, getwaterlevel());

  
  // set the status
  ThingSpeak.setStatus(myStatus);
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  
  // change the values

  delay(20000); // Wait 20 seconds to update the channel again
}

String getTemp() {
  DHT.read(DHT11_PIN);
  TempC = DHT.temperature;
  return String(TempC);
  return String(DHT.temperature);
}

String getHumi() {
  DHT.read(DHT11_PIN);
  Humidity = DHT.humidity;
  return String(Humidity);
  return String(DHT.humidity);
}

String getwateringsystem() {
  soilMoistureValue = analogRead(35);
  if (soilMoistureValue > WateredsoilValue) {
    Serial.println("Dry\nWatering ");
    delay(1000);
    digitalWrite(PERI_MOTOR, HIGH);
    delay(5000);
    return String("Dry");
  } else {        
    Serial.println("Wet\n Watering not needed");
    delay(1000);
    digitalWrite(PERI_MOTOR, LOW);
    delay(5000);
    return String("Wet");   

  }
}

String getwaterlevel() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2; //distance = (speed of sound(0.034) * pulse duration) / 2
  float waterLevel = ((25.4 - distance) / 25.4 ) * 100;

  Serial.print("Water level: ");
  Serial.print(waterLevel);
  Serial.println("%");

  delay(1000);
  return String(waterLevel);
}

