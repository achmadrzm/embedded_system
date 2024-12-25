#include <LowPower.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potensio = analogRead(A1);

  if(potensio >= 0 && potensio <= 512){ //batas bawah
    Serial.flush();
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
  else if(potensio >= 513 && potensio <=1023){ //batas atas
    Serial.flush();
    LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
  }
  Serial.println("Potensio: ");
  Serial.println(analogRead(A1));
}