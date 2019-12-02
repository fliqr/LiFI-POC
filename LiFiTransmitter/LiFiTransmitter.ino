#include <string.h>
#include <stdio.h>

String fileData = "01001010011101010111001101110100001000000110110101100001011010110110010100100000011010010111010000100000011101110110111101110010011010110010000001100001011011000111001001100101011000010110010001111001001011100010111000101110";
int outPin = 8;
int offTime = 1; //same as a zero bit
int startTime = 8;
int oneBitTime = 4;

void setup() {
  pinMode(outPin, OUTPUT);     //PIN Signal
  Serial.begin(9600);
}

void loop() {
  
  //Start Bit
  digitalWrite(outPin, HIGH);
  delay(offTime);
  digitalWrite(outPin, LOW);
  delay(startTime);
  digitalWrite(outPin, HIGH);
  delay(offTime);

  //Encoded Data
  for (int x = 0; x < fileData.length(); x++) {
    char a = fileData[x];
    const char *readBit = &a;
    if (strcmp(readBit, "1") == 0) {
      digitalWrite(outPin, LOW);
      delay(oneBitTime);
      digitalWrite(outPin, HIGH);
      delay(offTime);
    }
    if (strcmp(readBit, "0") == 0) {
      digitalWrite(outPin, LOW);
      delay(offTime);
      digitalWrite(outPin, HIGH);
      delay(offTime);
    }
  }
}
