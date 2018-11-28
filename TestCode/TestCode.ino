

const int soilMoisture = A0;
int soilPower = 5;
const int lightSensor = A1;
const int yellow = 11;
const int blue = 12;
const int red = 13;
int sensorValue = 0;

void setup() {

  Serial.begin(9600);
  pinMode(yellow,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(soilPower, OUTPUT);
}

void loop() {
  Serial.print("Light Sensor:  ");
  Serial.print(analogRead(lightSensor));
  Serial.print("   Soil Moisture:   ");
  sensorValue = readSoil();
  Serial.print(sensorValue);
  Serial.println();
  delay(300);
}

int readSoil(){
  digitalWrite(soilPower, HIGH);
  delay(10);
  int val = analogRead(soilMoisture);
  digitalWrite(soilPower, LOW);
  return val;
}
