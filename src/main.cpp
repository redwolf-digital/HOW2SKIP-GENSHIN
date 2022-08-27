#include <Arduino.h>
#include <Mouse.h>

bool Butt_Flags = 0;


void Butt_Event() {
  if(digitalRead(PB10) == LOW) {
    Butt_Flags = !Butt_Flags;
    
    if(Butt_Flags == 1) {
      digitalWrite(PC13, LOW);
    }else{
      digitalWrite(PC13, HIGH);
      Mouse.release(MOUSE_LEFT);
    }
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


void loop() {
  if(Butt_Flags == 1) {
    Mouse.click(MOUSE_LEFT);
  }
  //Assembly "NOP" to stop CPU operation for Delay  
  for(unsigned int i=0; i<250; i++) {
    asm volatile("nop");
  }
}