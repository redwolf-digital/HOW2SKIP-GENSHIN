#include <Arduino.h>
#include <Mouse.h>

bool Butt_Flags = 0;


void Butt_Event() {
  if(digitalRead(PB10) == LOW) {
    Butt_Flags = !Butt_Flags;
    delay(150);
  }
}


void setup() {
  Mouse.begin();
  pinMode(PC13, OUTPUT);
  pinMode(PB10, INPUT_PULLUP);
  digitalWrite(PC13, HIGH);

  attachInterrupt(digitalPinToInterrupt(PB10), Butt_Event, FALLING);
}


//TEST
void loop() {
  if(Butt_Flags == 1) {
    digitalWrite(PC13, LOW);
    Mouse.click();
  }else {
    digitalWrite(PC13, HIGH);
  }
}