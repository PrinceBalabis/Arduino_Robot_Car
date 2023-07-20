int reflectancePin1 = A4, reflectancePin2 = A5, reflectancePin3 = A6, reflectancePin4 = A7,
    reflectancePin5 = A8, reflectancePin6 = A9, reflectancePin7 = A10, reflectancePin8 = A11;

int reflectanceCalibration1 = 0, reflectanceCalibration2 = 0, reflectanceCalibration3 = 0, reflectanceCalibration4 = 0,
    reflectanceCalibration5 = 0, reflectanceCalibration6 = 0, reflectanceCalibration7 = 0, reflectanceCalibration8 = 0;

// variables to store the value coming from the sensor
int reflectance1 = 0, reflectance2 = 0, reflectance3 = 0, reflectance4 = 0,
    reflectance5 = 0, reflectance6 = 0, reflectance7 = 0, reflectance8 = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(115200);

  // Some time to startup
  delay(2000);

  calibrate_reflectance_sensor();
}

void calibrate_reflectance_sensor() {
  int calibrationSamples = 2000;
  for (int i = 0; i < calibrationSamples; i++) {
    read_sensor();
    reflectanceCalibration1 += reflectance1;
    reflectanceCalibration2 += reflectance2;
    reflectanceCalibration3 += reflectance3;
    reflectanceCalibration4 += reflectance4;
    reflectanceCalibration5 += reflectance5;
    reflectanceCalibration6 += reflectance6;
    reflectanceCalibration7 += reflectance7;
    reflectanceCalibration8 += reflectance8;
    delay(2);
  }

  reflectanceCalibration1 /= calibrationSamples;
  reflectanceCalibration2 /= calibrationSamples;
  reflectanceCalibration3 /= calibrationSamples;
  reflectanceCalibration4 /= calibrationSamples;
  reflectanceCalibration5 /= calibrationSamples;
  reflectanceCalibration6 /= calibrationSamples;
  reflectanceCalibration7 /= calibrationSamples;
  reflectanceCalibration8 /= calibrationSamples;

  delay(5000);
}

void read_sensor() {
  reflectance1 = analogRead(reflectancePin1);
  reflectance2 = analogRead(reflectancePin2);
  reflectance3 = analogRead(reflectancePin3);
  reflectance4 = analogRead(reflectancePin4);
  reflectance5 = analogRead(reflectancePin5);
  reflectance6 = analogRead(reflectancePin6);
  reflectance7 = analogRead(reflectancePin7);
  reflectance8 = analogRead(reflectancePin8);
}

void read_sensor_calibrated() {
  reflectance1 = analogRead(reflectancePin1) - reflectanceCalibration1;
  reflectance2 = analogRead(reflectancePin2) - reflectanceCalibration2;
  reflectance3 = analogRead(reflectancePin3) - reflectanceCalibration3;
  reflectance4 = analogRead(reflectancePin4) - reflectanceCalibration4;
  reflectance5 = analogRead(reflectancePin5) - reflectanceCalibration5;
  reflectance6 = analogRead(reflectancePin6) - reflectanceCalibration6;
  reflectance7 = analogRead(reflectancePin7) - reflectanceCalibration7;
  reflectance8 = analogRead(reflectancePin8) - reflectanceCalibration8;
}

void print_sensor() {
  Serial.print("Sensor1:");
  Serial.print(reflectance1);
  Serial.print(",Sensor2:");
  Serial.print(reflectance2);
  Serial.print(",Sensor3:");
  Serial.print(reflectance3);
  Serial.print(",Sensor4:");
  Serial.print(reflectance4);
  Serial.print(",Sensor5:");
  Serial.print(reflectance5);
  Serial.print(",Sensor6:");
  Serial.print(reflectance6);
  Serial.print(",Sensor7:");
  Serial.print(reflectance7);
  Serial.print(",Sensor8:");
  Serial.print(reflectance8);

  Serial.println("");
}

void loop() {
  read_sensor_calibrated();
  print_sensor();
  delay(50);
}
