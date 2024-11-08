//#include <SoftwareSerial.h>

//#define RX D7
//#define TX D8
SoftwareSerial LoRaSerial(RX, TX); // RX, TX

void setup() {
  Serial.begin(115200); // Initialize USB Serial
  Serial.swap();
  delay(1000);
  
  LoRaSerial.begin(115200); // Initialize Software Serial
  
}

void loop() {
  // Check if data is available on USB Serial
  while (Serial.available()) {
    String data = Serial.readString();
    LoRaSerial.println(data); // Send data to Software Serial

    //Serial.flush() //is very slow
  }

  // Check if data is available on Software Serial
  while (LoRaSerial.available()) {
    String data = LoRaSerial.readString();
    Serial.println(data); // Send data to USB Serial

    //LoRaSerial.flush();
  }
}