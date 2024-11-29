// Constants
const int pulsePin = A0; // Pulse sensor connected to analog pin A0
const int ledPin = 13;   // LED connected to digital pin 13
const int threshold = 60; // Heart rate threshold (beats per minute)

// Variables
int pulseValue = 0;
int heartRate = 0;
unsigned long lastBeatTime = 0;
unsigned long currentTime = 0;

void setup() {
  pinMode(pulsePin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pulseValue = analogRead(pulsePin);
  currentTime = millis();

  // Simulate heart rate calculation (this is a simplified example)
  if (pulseValue > 512) { // Assuming a threshold for detecting a heartbeat
    unsigned long beatInterval = currentTime - lastBeatTime;
    lastBeatTime = currentTime;
    heartRate = 60000 / beatInterval; // Calculate heart rate in BPM
    Serial.print("Heart Rate: ");
    Serial.println(heartRate);
  }

  // Check if heart rate is below the threshold
  if (heartRate < threshold && (currentTime - lastBeatTime) > 1000) {
    digitalWrite(ledPin, HIGH); // Simulate pacing pulse
    delay(100); // Pulse duration
    digitalWrite(ledPin, LOW);
    Serial.println("Pacing Pulse Generated");
  }

  delay(10); // Small delay to stabilize readings
}
