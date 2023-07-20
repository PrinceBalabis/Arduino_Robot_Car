void setup() {
  setup_serial();
  setup_motors();
  calibrate_reflectance_sensor();
  setup_pid();

  Serial.println("Starting...");
}

void loop() {
  run_pid();
  run_serial_logger();
}