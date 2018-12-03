/********************************************************************
 *
 * Copyright Luighi Vitón, 2018
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 ********************************************************************
*/

#include "isfetboard.h"
#define RXPIN 10
#define TXPIN 11

IsfetBoard myboard(RXPIN,TXPIN);

int counter=0;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float pHcomp = NAN;
  float pH = NAN;
  float temperature = NAN;

  myboard.readData();
  pHcomp = myboard.pHcomp;
  pH = myboard.pH;
  temperature = myboard.temperature;
  
  counter++;
  Serial.print("Data: "); 
  Serial.print(counter);
  Serial.print(" :: ");
  Serial.print("pHcomp: ");
  Serial.print(pHcomp);
  Serial.print(" pH: ");
  Serial.print(pH);
  Serial.print(" Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  delay(10000);
}
