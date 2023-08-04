#include <QTRSensors.h>

QTRSensors qtr;

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];


void setup_reflectance_sensor() {
  // configure the sensors
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){ A4, A5, A6, A7, A8, A9, A10, A11 }, SensorCount);

  calibrate_reflectance_sensor();

  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on
  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
}

void calibrate_reflectance_sensor() {
  for (uint16_t i = 0; i < 2000; i++) {
    qtr.calibrate();
  }
  delay(10);
}

void reflectance_block_until_black_line() {
  while (sensorPosition <= 3000 || sensorPosition >= 4000) {
    run_black_line_detection();
    delay(1);
  }
}

void run_black_line_detection() {
  sensorPosition = qtr.readLineBlack(sensorValues);
}

void print_sensor_values() {
  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(",Sensor");
    Serial.print(i + 1);
    Serial.print(":");
    Serial.print(sensorValues[i]);
  }
  Serial.println("");
}
