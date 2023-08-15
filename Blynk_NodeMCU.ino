#include <BlynkSimpleEsp8266.h>

char auth[] = "Your_Blynk_Auth_Token";  // Replace with your Blynk auth token

#define SOLENOID_PIN D1   // GPIO pin connected to MOSFET gate
#define BUZZER_PIN D2     // GPIO pin connected to the buzzer

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, "Your_SSID", "Your_Password");  // Replace with your WiFi credentials
  pinMode(SOLENOID_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(SOLENOID_PIN, LOW);  // Initialize solenoid as OFF
  digitalWrite(BUZZER_PIN, LOW);    // Initialize buzzer as OFF
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V1) {  // Virtual pin V1 in Blynk app
  int buttonState = param.asInt();  // Get value from the Blynk app button

  if (buttonState == 1) {  // If button is pressed
    digitalWrite(SOLENOID_PIN, HIGH);  // Turn on the solenoid lock
    digitalWrite(BUZZER_PIN, HIGH);    // Turn on the buzzer
  } else {
    digitalWrite(SOLENOID_PIN, LOW);   // Turn off the solenoid lock
    digitalWrite(BUZZER_PIN, LOW);      // Turn off the buzzer
  }
}
