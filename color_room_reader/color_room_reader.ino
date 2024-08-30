//4 pin led
const int greenLEDPin = 9;
const int blueLEDPin = 10;
const int redLEDPin = 11;

// p-resistor pins
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

//fading led conditions
int redValue = 0;
int blueValue = 0;
int greenValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600); // start the serial port to track readings 

// set the colors of the 4 pin led as the output of reading from p-resistor
  pinMode(greenLEDPin , OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode (redLEDPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);

  //print out the raw sensor values;
  Serial.print("Raw Sensor Values \t red: " );
  Serial.print (redSensorValue);
  Serial.print("\t blue: ");
  Serial.print (blueSensorValue);
  Serial.print("\t green: ");
  Serial.println (greenSensorValue);

  //convert 
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print("Mapped Sensor Values \t red:  ");
  Serial.print(redValue);
  Serial.print ("\t blue: ");
  Serial.print(blueValue);
  Serial.print("\t green: ");
  Serial.println(greenValue);

  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);
  analogWrite(greenLEDPin , greenValue);

}
