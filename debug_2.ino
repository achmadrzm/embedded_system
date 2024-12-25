#define LED_MERAH 13
#define LED_KUNING 12
#define LED_HIJAU 11
#define TOMBOL 2

int state = 1;
int input_sblm = HIGH;
int tepi_naik = HIGH;
unsigned long waktu_debouncing = 0;
unsigned long delay_debouncing = 50;
int input = LOW;
int kondisi_sblm = LOW;
unsigned long waktu_state = 0;
unsigned long delay_state2; //hijau
unsigned long delay_state3 = 2000; //kuning
unsigned long delay_state4; //merah

void state_1();
void state_2();
void state_3();
void state_4();

void setup() {
  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_KUNING, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(TOMBOL, INPUT_PULLUP);

  Serial.begin(9600);
}
void loop() {
  int potensio = analogRead(A1);
  int kondisi = digitalRead(TOMBOL);
  
  if (kondisi != kondisi_sblm) {
    waktu_debouncing = millis();
  }
  if ((millis() - waktu_debouncing) > delay_debouncing) {
    if (kondisi != input) {
      input = kondisi;
    }
  }

  kondisi_sblm = kondisi;
  //untuk debouncing
  if (input == LOW && input_sblm == HIGH) {
    input_sblm = input;}
  else if (input == HIGH && input_sblm == LOW) {
    input_sblm = input;
    tepi_naik = LOW;
  }

  if(potensio >= 512 && potensio <= 1023){
    delay_state2 = 10000; //hijau
    delay_state4 = 3000; //merah
  }
  else if(potensio >= 0 && potensio <= 511){
    delay_state2 = 5000; //hijau
    delay_state4 = 8000; //merah
  }

  switch (state) {
    case 1:
      state_1();
      if (tepi_naik == LOW) {
        state = 2;
        waktu_state = millis();
      }
      break;
    case 2:
      state_2();
      if ((millis() - waktu_state) > delay_state2) {
        state = 3;
        waktu_state = millis();
      }
      break;
    case 3:
      state_3();
      if ((millis() - waktu_state) > delay_state3) {
        state = 4;
        waktu_state = millis();
      }
      break;
    case 4:
      state_4();
      if ((millis() - waktu_state) > delay_state4) {
        state = 2;
        waktu_state = millis();
      }
      break;
    }
    tepi_naik = HIGH;
    Serial.print("Current State: ");
    Serial.println(state);
}

void state_1() {
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_HIJAU, LOW);
  }
void state_2() {
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(LED_HIJAU, HIGH);
  digitalWrite(LED_KUNING, LOW);
  }
void state_3() {
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(LED_KUNING, HIGH);
  digitalWrite(LED_HIJAU, LOW);
}
  void state_4() {
  digitalWrite(LED_MERAH, HIGH);
  digitalWrite(LED_HIJAU, LOW);
  digitalWrite(LED_KUNING, LOW);
}