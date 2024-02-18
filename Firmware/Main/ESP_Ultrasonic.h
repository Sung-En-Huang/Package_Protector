#ifndef ESP_ULTRASONIC_h
#define ESP_ULTRASONIC_h

#include <ESP8266HTTPClient.h>

const int trigPin = 15;
const int echoPin = 13;
double startTime = 0;
double elapsedTime = 0; 

// define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034

long duration;
float distanceCm;

bool monitor()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    distanceCm = duration * SOUND_VELOCITY / 2;
    Serial.println(distanceCm);
    // if (distanceCm < 75) {
    //     // If the object is within 50 cm, start or reset the timer
    //     Serial.println("Detected");
    //     if (startTime == 0) {
    //         Serial.println("millis");
    //         startTime = millis();
    //     }
    //     Serial.println("outside");
    //     // Calculate the elapsed time
    //     elapsedTime = millis() - startTime;

    //     // Check if the object has been within 50 cm for 3 seconds
    //     if (elapsedTime >= 3000) {
    //         WiFiClient wifiClient;
    //         HTTPClient http;
    //         // Specify the target URL
    //         http.begin(wifiClient, url);

    //         // Send a GET request
    //         int httpCode = http.GET();

    //         if (httpCode > 0) {
    //           // Successful GET request
    //           String payload = http.getString();
    //           Serial.println("HTTP GET Request Response:");
    //           Serial.println(payload);
    //         } else {
    //           // Failed GET request
    //           Serial.println("HTTP GET request failed");
    //         }

    //         // Close the connection
    //         http.end();
    //         delay(2000);
    //         Serial.println("Object has been within 50 cm for 3 seconds!");

    //         return true;
    //     }

    // } else {
    //     // If the object is not within 50 cm, reset the timer
    //     startTime = 0;
    // } 

    return distanceCm <= 10.0;
}

bool timeCounter()
{
    if (startTime == 0)
    {
        // Serial.println("millis");
        startTime = millis();
    }
    elapsedTime = millis() - startTime;

    if (elapsedTime >= 3000)
    {
        startTime = 0;
        return true;
    } else {
      return false;
    }
}
#endif