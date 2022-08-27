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
  //Keyboard.begin();
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
    /*
    Keyboard.write(0x20);
    delay(250);
    Keyboard.release(0x20);
    delay(250);
    */
  }else {
    digitalWrite(PC13, HIGH);
  }
}