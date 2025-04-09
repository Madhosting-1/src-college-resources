#define LED_PIN 8
#define BUTTON_PIN 7

int buttonReading = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  buttonReading = digitalRead(BUTTON_PIN);

  if (buttonReading == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
