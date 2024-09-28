#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>


const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

int solenoidPin = 5;
int ledPin = 6;
int buzzerPin = 4;
int relayPin = 3;
int buttonPin = 2;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init(); 
  lcd.begin(16, 2); 
  lcd.print("Scan your card");

  pinMode(solenoidPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  digitalWrite(solenoidPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;
    
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  

  if (uid.equalsIgnoreCase("a1b2c3d4")) {
    unlockDoor();
  } else {
    lcd.clear();
    lcd.print("Access Denied");
    digitalWrite(buzzerPin, HIGH); 
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    lcd.clear();
    lcd.print("Scan your card");
  }

  delay(2000); 
  rfid.PICC_HaltA();
}

void unlockDoor() {
  lcd.clear();
  lcd.print("Access Granted");
  digitalWrite(ledPin, HIGH); 
  digitalWrite(solenoidPin, HIGH); 
  digitalWrite(relayPin, HIGH);      

  delay(5000); 
  

  digitalWrite(solenoidPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, LOW);
  lcd.clear();
  lcd.print("Scan your card");
}
