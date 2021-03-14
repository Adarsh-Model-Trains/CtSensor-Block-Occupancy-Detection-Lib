
#include "CtSensor.h"

#define CT_SENSOR_COUNT 5

CtSensor ctSensor;

void setup() {
  Serial.begin(9600);
  ctSensor.initCtSensor(CT_SENSOR_COUNT);
  ctSensor.setSensorPin(1, 13);
  ctSensor.setSensorPin(2, 12);
  ctSensor.setSensorPin(3, 11);
  ctSensor.setSensorPin(4, 10);
  ctSensor.setSensorPin(5, 9);
}

void loop() {
  delay(500);
  Serial.println();
  ctSensor.displayPins();
  for (int pinNo = 1; pinNo <= CT_SENSOR_COUNT; pinNo++) {
    bool state = ctSensor.isSensorActive(pinNo);
    if (state) {
      Serial.print("SENSOR PIN NO ");
      Serial.print(pinNo);
      Serial.print(" SENSOR PIN STATE ");
      Serial.println(state);
    }
  }
}
