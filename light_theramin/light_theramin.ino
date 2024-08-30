int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,HIGH);
  //callibrate the phototransresistor
  while(millis() < 5000)
  {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }
  digitalWrite (ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 10, 5000); // 50 and 40000 reflect the range of frequencies that the piezo can produce;
  tone (8, pitch, 20); //play pitch through pin 8 for 20 ms
  delay(10);
}
