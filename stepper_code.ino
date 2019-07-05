// defines pins numbers
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "80420d2c49d44c52a072faad9dc7bbb4";
char ssid[] = "SWZ";
char pass[] = "12345678a";

int button, button_time, button_direction, button_veces, k;
bool button_pulsador = false;
const int stepPin = 27;
const int dirPin = 14;
/*const int ledPin = 34;*/

BLYNK_WRITE(V0)
{
  button = param.asInt();
}

BLYNK_WRITE(V1)
{
  button_time = param.asInt();
}

BLYNK_WRITE(V2)
{
  button_direction = param.asInt();
}

BLYNK_WRITE(V3)
{
  button_veces = param.asInt();
  }

BLYNK_WRITE(V4)
{
  button_pulsador = param.asInt();
  }

  
void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  /*pinMode(ledPin, OUTPUT);*/
}

int direccion() {
  if (button_direction == 1) {
    Serial.println("A la derecha");
    return HIGH;
  }
  else if (button_direction == -1) {
    Serial.println("A la izquierda");
    return LOW;
  }
}


void loop() {
  Blynk.run();

  if ( button == 1 ) {
    digitalWrite(dirPin, direccion()); // Enables the motor to move in a particular direction
    /*digitalWrite(ledPin, HIGH);*/
    Serial.println(" El sistema está encendido ");
    //Serial.println(button);
    if (button_time == 0) {
      Serial.print("button_time(OFF): ");
      Serial.println(button_time);
    }
    else if (button_time != 0 &&  button_time > 0 ) {
      Serial.print("buton_time(ON): ");
      Serial.println(button_time);

      if (button_veces == 1 && button_pulsador == true) {
        for (int x = 0; x<1; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(k);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(k);
          }
        button_pulsador == false;
        } 

      else if (button_veces == 2 && button_pulsador == true) {
        for (int x = 0; x<2; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(k);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(k);
          }
        button_pulsador == false;
        } 

      else if (button_veces == 3 && button_pulsador == true) {
        for (int x = 0; x<3; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(k);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(k);
          }
        button_pulsador == false;
        }   

      else if (button_veces == 4 && button_pulsador == true) {
        for (int x = 0; x<4; x++){
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(k);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(k);
          }
        button_pulsador == false;
        } 
      
    }
    
   else if ( button == 0) {
     /*digitalWrite(ledPin, LOW);*/
     Serial.println(" El sistema está apagado ");
    }
  }
}
