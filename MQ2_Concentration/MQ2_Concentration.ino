// Constants
const int sensorPin = A0; // MQ2 sensor connected to analog pin A0
const float Vcc = 5.0;    // Supply voltage
const float RL = 20000.0; // Load resistance (20 kΩ)
const float R0 = 10000.0; // Baseline resistance in clean air (10 kΩ)

// Calibration constants for LPG (adjust for specific gas type)
const float a = -2.3; // Slope from the sensor's datasheet
const float b = 0.93; // Intercept from the sensor's datasheet

// Define output pins
const int range1Pin = 24; // For range 201-300 ppm
const int range2Pin = 26; // For range 301-400 ppm
const int range3Pin = 28; // For range 401-500 ppm
const int range4Pin = 30; // For range 501-600 ppm

void setup() {
  Serial.begin(9600);

  // Configure pins as output
  pinMode(range1Pin, OUTPUT);
  pinMode(range2Pin, OUTPUT);
  pinMode(range3Pin, OUTPUT);
  pinMode(range4Pin, OUTPUT);

  // Initialize all pins to LOW
  digitalWrite(range1Pin, LOW);
  digitalWrite(range2Pin, LOW);
  digitalWrite(range3Pin, LOW);
  digitalWrite(range4Pin, LOW);
}

void loop() {
  int analogValue = analogRead(sensorPin); // Read analog value (0-1023)
  float Vout = (analogValue / 1023.0) * Vcc; // Convert analog value to voltage
  float Rs = RL * ((Vcc - Vout) / Vout);    // Calculate sensor resistance

  // Calculate ppm using the calibration formula
  float ratio = Rs / R0; // Ratio of Rs to R0
  float ppm = pow(10, (a * log10(ratio) + b)); // Logarithmic formula for ppm

  // Clamp ppm values to the practical range
  if (ppm < 200) {
    ppm = 200; // Minimum ppm
  } else if (ppm > 10000) {
    ppm = 10000; // Maximum ppm
  }

  // Control output pins based on ppm ranges
  if (ppm > 200 && ppm <= 2500) {
    digitalWrite(range1Pin, HIGH);
    digitalWrite(range2Pin, LOW);
    digitalWrite(range3Pin, LOW);
    digitalWrite(range4Pin, LOW);
  } else if (ppm > 2500 && ppm <= 5000) {
    digitalWrite(range1Pin, LOW);
    digitalWrite(range2Pin, HIGH);
    digitalWrite(range3Pin, LOW);
    digitalWrite(range4Pin, LOW);
  } else if (ppm > 5000 && ppm <= 7500) {
    digitalWrite(range1Pin, LOW);
    digitalWrite(range2Pin, LOW);
    digitalWrite(range3Pin, HIGH);
    digitalWrite(range4Pin, LOW);
  } else if (ppm > 7500 && ppm <= 10000) {
    digitalWrite(range1Pin, LOW);
    digitalWrite(range2Pin, LOW);
    digitalWrite(range3Pin, LOW);
    digitalWrite(range4Pin, HIGH);
  } else {
    // Turn off all pins if ppm is outside the specified ranges
    digitalWrite(range1Pin, LOW);
    digitalWrite(range2Pin, LOW);
    digitalWrite(range3Pin, LOW);
    digitalWrite(range4Pin, LOW);
  }

  // Display the results on the Serial Monitor
  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(" | Voltage: ");
  Serial.print(Vout, 2);
  Serial.print(" V | Rs: ");
  Serial.print(Rs, 2);
  Serial.print(" Ohms | PPM: ");
  Serial.println(ppm, 2); // Display ppm with 2 decimal places

  delay(1000); // Wait for 1 second before the next reading
}
