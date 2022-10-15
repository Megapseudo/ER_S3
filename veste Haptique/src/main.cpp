#include <Arduino.h>
#include "WiFi.h"
// Nom et Mot de passe du réseau WiFi
/*
const char* ssid = "Sir Remy";
const char* password = "objectifRemysurletoitdumondeen2022";
*/
const char* ssid = "freebox-3336AD";
const char* password = "mkh94q2hbtqmrwxvqwhbrd";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //création de la liason ESP/console (paramettre =Nbbaud)
  delay(1000);

  WiFi.mode(WIFI_STA); // met l'ESP en mode client 
  WiFi.begin(ssid, password); //se connecte au réseau wifi 
  Serial.println("\n Connecting"); 
  
  while(WiFi.status()!= WL_CONNECTED) // écrit des points tant que la connection n'est pas faite
    {
      Serial.print("."); 
      delay(1000);
    }
  Serial.println("\nConnected to the WiFi network"); //message qui nous informe de la réussite de la connection
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP()); // IP qui nous as été attribuer dans le réseau

}


void loop() {
  // put your main code here, to run repeatedly:
}