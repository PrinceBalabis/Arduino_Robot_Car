uint32_t serialRateTimer;
uint32_t serialRateTarget = 75;  //milliseconds


void setup_serial() {
  Serial.begin(115200);
  serialRateTimer = millis();
}

void run_serial_logger() {
  if (millis() - serialRateTimer > serialRateTarget) {

    Serial.print("sensorPosition:");
    Serial.print(sensorPosition);
    Serial.print(",pidOutput:");
    Serial.print(output);
    Serial.print(",motorSpeedLeft:");
    Serial.print(motorSpeedLeft);
    Serial.print(",motorSpeedRight:");
    Serial.print(motorSpeedRight);

    Serial.println("");
    serialRateTimer = millis();  // Update timer when last executed
  }
}
