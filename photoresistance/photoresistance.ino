int piezoPin=8;
int ldrPin=0;
int ldrValue=0;

void setup() {
Serial.begin(9600);

}

void loop() {
ldrValue=analogRead(ldrPin);
Serial.print(ldrValue);
Serial.print("\n");
tone(piezoPin,1000);
delay(25);
noTone(piezoPin);
delay(ldrValue);

}
