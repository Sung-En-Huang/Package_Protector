#include "ESP_Servo.h"
#include "ESP_Ultrasonic.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// network credentials
const char* ssid     = "LAPTOP-SVH5PD8U 7039";
const char* password = "8796L7u<";
WiFiServer server(80);
// Variable to store the HTTP request
String header;
bool lockDoor = true;
IPAddress staticIP(192, 168, 137, 125);  // Set the static IP address for this device
IPAddress gateway(192, 168, 137, 1);     // Set the gateway IP address (router)
IPAddress subnet(255, 255, 225, 0);    // Set the subnet mask


void setup()
{
    Serial.begin(115200);

    // Wifi set up
    WiFi.begin(ssid, password);
    WiFi.config(staticIP, gateway, subnet);  // Set static IP, gateway, and subnet
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
  
    server.begin();
    // pinMode(trigPin, OUTPUT);
    // pinMode(echoPin, INPUT);
    servo1.attach(servoPin, 500, 2400);
    servo1.write(0);
}

void loop()
{
    // while (monitor())
    // {
    //     //Serial.println("Activated");
    //     //Serial.println("---------");
    //     unlock_pos();
    // }
    // //delay(1000);
    // lock_pos();
    //delay(1000);

    // listen for incoming clients
    WiFiClient client = server.available();

    if (client) {                             
        String currentLine = "";                
        while (client.connected()) {
            if (client.available()) {             
                char c = client.read();            
                header += c;
                if (c == '\n') {                 
                    if (currentLine.length() == 0) {
                        // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                        // and a content-type so the client knows what's coming, then a blank line:
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println("Connection: close");
                        client.println();
                        if (header.indexOf("GET /unlock") >= 0) {
                            Serial.println("It's Unlocked");
                            unlock_pos();
                            lockDoor = false;
                            break;
                            
                        } else if (header.indexOf("GET /lock") >= 0) {
                            lockDoor = true;
                            lock_pos();
                            break;
                        }
                        break;
                    } else { // if you got a newline, then clear currentLine
                        currentLine = "";
                    }
                } else if (c != '\r') {  // if you got anything else but a carriage return character,
                    currentLine += c;      // add it to the end of the currentLine
                }
            
            }
        }
        client.stop();
        header = "";
        Serial.println("disconnected");
    }
    delay(1000);
}