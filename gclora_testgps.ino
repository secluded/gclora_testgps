// test a passthru between USB and hardware serial

void setup() {
  Serial.println("GPS echo test");
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  Serial.begin(9600);
  Serial1.begin(9600);      // default NMEA GPS baud
}


void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial1.write(c);
  }
  if (Serial1.available()) {
    char c = Serial1.read();
    Serial.write(c);
  }
}
