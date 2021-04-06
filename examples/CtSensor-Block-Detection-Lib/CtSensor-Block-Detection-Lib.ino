
#include "CtSensor.h"

#define CT_SENSOR_COUNT 2
#define X_BLOCK_LED 13
#define Y_BLOCK_LED 12

CtSensor ctSensor;

void setup() {
  Serial.begin(9600);
  ctSensor.initCtSensor(CT_SENSOR_COUNT);
  ctSensor.setSensorPin(1, 7);
  ctSensor.setSensorPin(2, 6);
  pinMode(X_BLOCK_LED, OUTPUT);
  pinMode(Y_BLOCK_LED, OUTPUT);
}

void loop() {
  Serial.println();

  bool xBlockState = ctSensor.isSensorActive(1);
  if (xBlockState) {
    digitalWrite(X_BLOCK_LED, HIGH);
  } else {
    digitalWrite(X_BLOCK_LED, LOW);
  }

  bool yBlockState = ctSensor.isSensorActive(2);
  if (yBlockState) {
    digitalWrite(Y_BLOCK_LED, HIGH);
  } else {
    digitalWrite(Y_BLOCK_LED, LOW);
  }
}
