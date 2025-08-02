#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>

// RFID module pins
#define RST_PIN 9
#define SS_PIN 10

MFRC522 rfid(SS_PIN, RST_PIN);  // Create RFID instance

const int rs = 2, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String accessGranted[11] = {
  "53141095103", "1110143111413", "710101024413", "131070211413",
  "131011224413", "21041318413", "01031418413", "10103018413",
  "121011123413", "1510136210413", "1102532413"
};

int accessGrantedSize = 11;
#define RELAY 3         
bool locked = true;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();  // Initialising the  RFID

  lcd.begin(16, 2);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);

  lcd.print("#ACCESS CONTROL#");
  lcd.setCursor(0, 1);
  lcd.print("    Scan Tag");

  Serial.println("Place card/tag near reader...");
}

void loop() {
  // Look for new cards
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  String temp = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    temp += String((rfid.uid.uidByte[i] >> 4) & 0x0F);
    temp += String(rfid.uid.uidByte[i] & 0x0F);
  }

  Serial.print("The card's ID number is: ");
  Serial.println(temp);
  checkAccess(temp);

  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD
}

void checkAccess(String temp) {
  bool granted = false;
  for (int i = 0; i < accessGrantedSize; i++) {
    if (accessGranted[i] == temp) {
      Serial.println("Access Granted");
      granted = true;

      lcd.clear();
      lcd.print(" ACCESS GRANTED");

      if (locked) {
        lcd.setCursor(1, 1);
        lcd.print("OPENING DOOR");
        digitalWrite(RELAY, LOW);
        locked = false;
      } else {
        lcd.setCursor(1, 1);
        lcd.print("CLOSING DOOR");
        digitalWrite(RELAY, HIGH);
        locked = true;
      }
      break;
    }
  }

  if (!granted) {
    Serial.println("Access Denied");
    lcd.clear();
    lcd.print("ACCESS DENIED");
  }
}
