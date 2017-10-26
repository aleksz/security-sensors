int sensorPin = A1;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int threshold = 50;
int coolDownMillis = 500;
unsigned long alarmCooldownStart;
boolean alarmRaised;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
//  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    alarmCooldownStart = millis();  
    if (!alarmRaised) {
      alarmRaised = true;
      Serial.println("ALARM");
      digitalWrite(ledPin, HIGH);  
    } 
  } else {
    if (millis() - alarmCooldownStart >= coolDownMillis && alarmRaised) {
      alarmRaised = false;
      digitalWrite(ledPin, LOW);
      Serial.println("OK");        
    }
  }

  delay(1);
}
