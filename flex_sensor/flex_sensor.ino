
const int pin = A0;
int flexReading;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  flexReading = analogRead(pin);
  Serial.print("Value = ");
  Serial.println(flexReading);
  delay(600);
  
}
