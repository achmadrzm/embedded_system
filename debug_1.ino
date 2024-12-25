#define tombol A0

char pinsCount=2;
int pins[]={5,6};
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0; i<pinsCount; i++){
    pinMode(pins[i],OUTPUT);
  }
  pinMode(tombol, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A1);
  val = digitalRead(tombol);

  bool value1 = false;
  bool value2 = false;
  bool value3 = false;
  bool value4 = false;

  value1 = map(sensorValue, 0, 1023, 0, 255);
  value2 = map(sensorValue, 0, 1023, 512, 767);
  value3 = map(sensorValue, 0, 1023, 256, 511);
  value4 = map(sensorValue, 0, 1023, 768, 1023);
  Serial.println(sensorValue);

  if((value1 == true || value2 == true) && val == LOW){ //
    digitalWrite(pins[0], HIGH);
    digitalWrite(pins[1], LOW); //haursnya nyala hijau
    delay(500);
  }
  else if((value3 == true || value4 == true) && val == HIGH){
    digitalWrite(pins[1], HIGH);
    digitalWrite(pins[0], LOW); //harusnya nyala merah
    delay(500);
  }
}
