/*********"https://www.wikipedia.org/";
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Replace with your network credentials
const char* ssid     = "LAPTOP-SVH5PD8U 7039";
const char* password = "8796L7u<";
const char* url =  "https://jsonplaceholder.typicode.com/posts/1";// Replace with the target website URL

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

bool lockDoor = true;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Timeout time is 1 hr
const long timeoutTime = 1000*60*60;

void setup() {
  Serial.begin(115200);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected()) {
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /unlock") >= 0) {
              Serial.println("Unlocked");
              lockDoor = false;
            } else if (header.indexOf("GET /lock") >= 0) {
              Serial.println("Locked");
              lockDoor = true;
            }
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
          
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();

            WiFiClient wifiClient;
             // Create an HTTPClient object
            HTTPClient http;

            // Specify the target URL
            http.begin(wifiClient, url);

            // Send a GET request
            int httpCode = http.GET();

            if (httpCode > 0) {
              // Successful GET request
              String payload = http.getString();
              Serial.println("HTTP GET Request Response:");
              Serial.println(payload);
            } else {
              // Failed GET request
              Serial.println("HTTP GET request failed");
            }

            // Close the connection
            http.end();
            delay(2000);
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    // client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}