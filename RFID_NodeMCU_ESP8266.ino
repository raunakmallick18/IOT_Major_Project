#include <SPI.h>
#include <MFRC522.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Your_Blynk_Auth_Token";  // Replace with your Blynk auth token

#define SS_PIN D8   // Slave Select (SS) pin for MFRC522
#define RST_PIN D3  // Reset pin for MFRC522

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, "Your_SSID", "Your_Password");  // Replace with your WiFi credentials
  SPI.begin();      // Initialize SPI bus
  mfrc522.PCD_Init();  // Initialize MFRC522 RFID reader

  pinMode(D4, OUTPUT); // Notification LED
  digitalWrite(D4, LOW);
}

void loop() {
  Blynk.run();

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println("RFID Card Detected");

    // Send notification to Blynk app
    Blynk.notify("RFID Card Detected!");

    digitalWrite(D4, HIGH); // Turn on notification LED
    delay(1000);             // LED on for 1 second
    digitalWrite(D4, LOW);  // Turn off notification LED

    mfrc522.PICC_HaltA();   // Halt the card
  }
}
