//TEST

#include <Arduino.h>
#include <Keyboard.h>

bool Butt_Flags = 0;


void Butt_Event() {
  if(digitalRead(PB10) == LOW) {
    Butt_Flags = !Butt_Flags;
    delay(150);
  }
}


void setup() {
  Keyboard.begin();
  pinMode(PC13, OUTPUT);
  pinMode(PB10, INPUT_PULLUP);
  digitalWrite(PC13, HIGH);

  attachInterrupt(digitalPinToInterrupt(PB10), Butt_Event, FALLING);
}


//TEST
void loop() {
  if(Butt_Flags == 1) {
    digitalWrite(PC13, LOW);
    delay(100);
    digitalWrite(PC13, HIGH);
    delay(100);

  }else {
    digitalWrite(PC13, LOW);
    delay(1000);
    digitalWrite(PC13, HIGH);
    delay(1000);
  }
}