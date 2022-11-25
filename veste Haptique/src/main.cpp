#include <Arduino.h>
#include "WiFi.h"
#include "WebSockets.h"

char tempo;
void init_connection(); 
void TaskTCPlink( void *pvParameters );
void TaskTORlink( void *pvParameters );


void setup() {
  // put your setup code here, to run once:
  // launch wifi connection with ssid and password
  init_connection();
  // création des deux taches qu'on va utiliser
  xTaskCreate(TaskTCPlink,"TaskTPClink",1000,NULL,1,NULL);
  xTaskCreate(TaskTORlink,"TaskTORlink",1000,NULL,1,NULL);
}


void  loop() {
  // put your main code here, to run repeatedly:

}
void init_connection()

{
  // Nom et Mot de passe du réseau WiFi
//  réseau E&R :
const char* ssid = "Sir Remy";
const char* password = "objectifRemysurletoitdumondeen2022";
//   réseau maison
// const char* ssid = "F reebox-3336AD";
// const char* password = "nkh94q2hbtqmrwxvqwhbrd";
// réseau partage de co
// const char* ssid = "Keg Smash";
// const char* password = "12345678";


  Serial.begin(115200); //création de la liason ESP/console (paramettre =Nbbaud)
  delay(1000);

  WiFi.mode(WIFI_STA); // met l'ESP en mode client 
  WiFi.begin(ssid, password); //se connecte au réseau wifi 
  Serial.println("\n Connecting..."); 
  
  while(WiFi.status()!= WL_CONNECTED) // écrit des points tant que la connection n'est pas faite
    {
      Serial.print("."); 
      tempo++;
      delay(1000);
      if (tempo>=15)
      {
        Serial.println(WiFi.status());
        tempo = 0;
      }
    }
  Serial.println("\nConnected to the WiFi network"); //message qui nous informe de la réussite de la connection
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP()); // IP qui nous as été attribuer dans le réseau

}
void TaskTPClink(void*pvParameters)
{
while(1)
{
  
}

}
void TaskTORlink(void*pvParameters)
{
static int MT1=32, MT2=33,MT3=25,MT4=26,MT5=27,MT6=14,MT7 =12,MT8= 13;


while(1)
{
  
}

}