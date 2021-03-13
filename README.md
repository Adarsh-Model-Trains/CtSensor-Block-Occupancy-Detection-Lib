# CtSensor-Block-Detection-Lib

---

## About the Lib 
```
CtSensor-Block-Detection-Lib is for supporing multiple Ct Sensor Based Block together 
 with less complexcity of the programming 
 we can set the blocks sensors and their pin on arduino 
 and get the status of the sensors by calling methods for block occupancy decection 

```



## Connection Details 
```
pins which are configured on arduino program must have input from the
Ct sensors to those configured input pins 
and use the common gnd from the arduno to those CT sensors which are be read during the program exection 
```


## Steps for using lib

### include the header file

```
#include "CtSensor.h"
```

### define the number of the Ctsensor  we are about to use 
```
#define CT_SENSOR_COUNT 5
```

### define the object for the CtSensor
```
CtSensor ctSensor;
```

### initialize the CtSensor object for using its 
* ctSensor.initCtSensor(CT_SENSOR_COUNT);
```
void setup() {
	............
    ctSensor.initCtSensor(CT_SENSOR_COUNT);
  .............

}

```

### for debug messages a initialize Serial in setup
```

void setup() {
  
  Serial.begin(xxxx); // xxx can be any valid supported number 

  .........
}
```

### Configure the Sensors with sequence and its respective arduino pin 
* ctSensor.setSensorPin(CT_SENSOR_SEQUENCE_NUMBER, CT_SENSOR_ARDUINO_PIN_NUMBER);
```
void setup() {
  .................
  ctSensor.setSensorPin(1, 13);
  ctSensor.setSensorPin(2, 12);
  ctSensor.setSensorPin(3, 11);
  ctSensor.setSensorPin(4, 10);
  ctSensor.setSensorPin(5, 9);
  .................
}
```

### use lib method for getting the Ctsensor status 
* int state = ctSensor.getSensorState(CT_SENSOR_SEQUENCE_NUMBER);
	* it will return -1 when sequence number is invalid 
	* it will return 0 if sensor is active 
	* it will reurn 1 when sensor is inactive 
```
void loop() {
  delay(500);

     ...............

    int state = ctSensor.getSensorState(CT_SENSOR_SEQUENCE_NUMBER);
	...............
}
```

### ### use lib method for getting the Configured Sensor Pin List 
* tSensor.displayPins(); will print the data on serial monitor 
```
void loop() {
  delay(500);

     ...............

    ctSensor.displayPins();
	...............
}
```

### Complete Example
```

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
    int state = ctSensor.getSensorState(pinNo);
    if (state != -1) {
      Serial.print("SENSOR PIN NO ");
      Serial.print(pinNo);
      Serial.print(" SENSOR PIN STATE ");
      Serial.println(state);
    }
  }
}

```
