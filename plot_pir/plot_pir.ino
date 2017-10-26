const char SHORT_CISRCUIT = 'S';
const char SECURE = 'Y';
const char ALARM = 'A';
const char CUT = 'C';
const char HEALTH_CHECK = 'H';

const int ledPin = 13;      // select the pin for the LED

int sensorPins[] = {A0, A1};
int sensorValue[] = {0, 0};  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);

    initSensorPin(0);

  Serial.begin(9600);
  Serial.flush();
}

void loop() {
    checkSensor(0);
    delay(5);
}

void initSensorPin(int sensor) {
  pinMode(sensorPins[sensor], INPUT);
  digitalWrite(sensorPins[sensor], HIGH);  // set pullup on analog pin 0 
}

void checkSensor(int sensor) {
  sensorValue[sensor] = analogRead(sensorPins[sensor]);
  Serial.println(sensorValue[sensor]);
}

