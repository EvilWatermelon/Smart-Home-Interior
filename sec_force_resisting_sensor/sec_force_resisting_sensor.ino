const int pin = A0;
int forceReading;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  forceReading = analogRead(pin);
  if(forceReading >= 900) {
    Serial.println("Besetzt");
  } else {
    Serial.println("Nicht besetzt");
  }

delay(600);
}
