#include <Arduino.h>
#include "WiFi.h"
#include "WebSockets.h"

char tempo;
void init_connection(); 
void TaskTCPlink( void *pvParameters );
void TaskTORlink( void *pvParameters );
QueueHandle_t xQueue = xQueueCreate( 100000, sizeof( char) );
BaseType_t status;


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
static int Mout1=32, Mout2=33,Mout3=25,Mout4=26,Mout5=27,Mout6=14,Mout7 =12,Mout8= 13;//assignation des pins
static char ordreM1, ordreM2 ,ordreM3,ordreM4,ordreM5,ordreM6,ordreM7,ordreM8;// signaux TOR pour chaques moteurs
char octet;
status =xQueueReceive( xQueue,&octet, portMAX_DELAY);; 
//paramettrage  entrées/sorties
pinMode(Mout1,OUTPUT);
pinMode(Mout2,OUTPUT);
pinMode(Mout3,OUTPUT);
pinMode(Mout4,OUTPUT);
pinMode(Mout5,OUTPUT);
pinMode(Mout6,OUTPUT);
pinMode(Mout7,OUTPUT);
pinMode(Mout8,OUTPUT);  

while(1)
{
  //application d'un filtre pour récuperer le bit voulu
  ordreM1 = (octet>>0) & 0x01;
  ordreM2 = (octet>>1) & 0x01;
  ordreM3 = (octet>>2) & 0x01;
  ordreM4 = (octet>>3) & 0x01;
  ordreM5 = (octet>>4) & 0x01;
  ordreM6 = (octet>>5) & 0x01;
  ordreM7 = (octet>>6) & 0x01;
  ordreM8 = (octet>>7) & 0x01;
//ecriture des sorties GPIO
  if(ordreM1 !=0 ) digitalWrite(Mout1,HIGH);
  else digitalWrite(Mout1,HIGH);
  if(ordreM2 !=0 ) digitalWrite(Mout2,HIGH);
  else digitalWrite(Mout2,HIGH);
  if(ordreM3 !=0 ) digitalWrite(Mout3,HIGH);
  else digitalWrite(Mout3,HIGH);
  if(ordreM4 !=0 ) digitalWrite(Mout4,HIGH);
  else digitalWrite(Mout4,HIGH);
  if(ordreM5 != 0) digitalWrite(Mout5,HIGH);
  else digitalWrite(Mout5,HIGH);
  if(ordreM6 != 0) digitalWrite(Mout6,HIGH);
  else digitalWrite(Mout6,HIGH);
  if(ordreM7 != 0) digitalWrite(Mout7,HIGH);
  else digitalWrite(Mout7,HIGH);
  if(ordreM8 != 0) digitalWrite(Mout7,HIGH);
  else digitalWrite(Mout8,HIGH);
}

}