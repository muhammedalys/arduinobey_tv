#include <IRremote.h>

IRrecv irrecv(11);

decode_results results; 


#define BUTON0 65



void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
}

void loop() 
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value);
    if(results.value == BUTON0)
    digitalWrite( 3, !digitalRead(3));
    irrecv.resume();
  }
  
}
