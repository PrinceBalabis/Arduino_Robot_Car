uint16_t sensorPosition = 0;

void setup() {
  setup_serial();
  setup_motors();

  Serial.println("");
  Serial.println("");
  Serial.println("Starting calibration in 3 seconds...");
  delay(3000);

  Serial.println("Running calibration...");
  spin_calibration();

  Serial.println("Searching for black line...");
  search_black_line(false);

  Serial.println("Setting up PID...");
  setup_pid();

  Serial.println("Starting soon...");
}

void loop() {
  run_pid();
  run_serial_logger();
}