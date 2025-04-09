#define LED_PIN 9
#define POT_PIN A0

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pot_val = analogRead(POT_PIN);
  int brightness = pot_val / 4; // analogRead gives 0–1023, analogWrite needs 0–255

  analogWrite(LED_PIN, brightness);

  Serial.print("Potentiometer Value: ");
  Serial.print(pot_val);
  Serial.print(" → LED Brightness: ");
  Serial.println(brightness);

  delay(100); // Add a short delay to avoid flooding the serial monitor
}
