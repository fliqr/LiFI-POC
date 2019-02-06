#include <string.h>
#include <stdio.h>

String fileData = "0100100001100101011110010010000001001101011010010110101101100101001000000100010101101110011001110010000000101101001000000100100100100000011101000110100001101001011011100110101100100000011101110110010100100000011001110110111101110100001000000110100101110100001000000011101000101001";

void setup() {
  pinMode(8, OUTPUT);     //PIN Signal
  Serial.begin(9600);
}

void loop() {
  
  //Start Bit
  digitalWrite(8, LOW);
  delay(8);

  //Encoded Data
  for (int x = 0; x < fileData.length(); x++) {
    char a = fileData[x];
    const char *readBit = &a;
    if (strcmp(readBit, "1") == 0) {
      digitalWrite(8, HIGH);
      delay(2);
      digitalWrite(8, LOW);
      delay(1);
    }
    if (strcmp(readBit, "0") == 0) {
      digitalWrite(8, HIGH);
      delay(1);
      digitalWrite(8, LOW);
      delay(1);
    }
  }
}
