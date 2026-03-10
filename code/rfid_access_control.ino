#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
MFRC522 rfid(10, 9);
LiquidCrystal lcd(7, 6,5, 4,3, 2);
byte allowedUID[4] = {0x90, 0x89, 0x36, 0x52};
void setup() {
pinMode(A0, OUTPUT);
pinMode(A1, OUTPUT);
pinMode(8, OUTPUT);
lcd.begin(16, 2);
lcd.print("RFID Ready");
lcd.setCursor(0, 1);
lcd.print("Tap Card");
SPI.begin();
rfid.PCD_Init();
}
void loop() {
if (!rfid.PICC_IsNewCardPresent()) {
return;
}
if (!rfid.PICC_ReadCardSerial()) {
return;
}
int correct = 1;
for (int i = 0; i < 4; i++) {
if (rfid.uid.uidByte[i] != allowedUID[i]) {
correct = 0;
}
}
if (correct == 1) {
digitalWrite(A1, HIGH);
digitalWrite(A0, LOW);
lcd.clear();
lcd.print("Access Granted");
digitalWrite(8, HIGH);
delay(150);
digitalWrite(8, LOW);
} 
else {
digitalWrite(A0, HIGH);
digitalWrite(A1, LOW);
lcd.clear();
lcd.print("Access Denied");
digitalWrite(8, HIGH);
delay(120);
digitalWrite(8, LOW);
delay(120);
digitalWrite(8, HIGH);
delay(120);
digitalWrite(8, LOW);
}
rfid.PICC_HaltA();
rfid.PCD_StopCrypto1();
delay(2000);
digitalWrite(A0, LOW);
digitalWrite(A1, LOW);
lcd.clear();
lcd.print("RFID Ready");
lcd.setCursor(0, 1);
lcd.print("Tap Card");
}
