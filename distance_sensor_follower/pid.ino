#include "ArduPID.h"

ArduPID myController;

double input = 0;
double output = 0;

// Arbitrary setpoint and gains - adjust these as fit for your project:
double setpoint = 30;
double p = 15;
double i = 1;
double d = 0.5;

double minOutput = 50;  // The minimum output to send (plus or minus)

unsigned long timer = 0;
unsigned long timerInterval = 50;  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.

void setup_pid() {
  myController.begin(&input, &output, &setpoint, p, i, d);
  myController.reverse();
  myController.setSampleTime(100);  // OPTIONAL - will ensure at least 10ms have past between successful compute() calls
  myController.setOutputLimits(-255, 255);
  //myController.setBias(255.0 / 2.0);
  //myController.setWindUpLimits(-10, 10); // Groth bounds for the integral term to prevent integral wind-up

  myController.start();
}

void run_pid() {
  if (millis() - timer >= timerInterval) {

    input = read_ultrasonic();
    // Serial.print((double)input);  // Send ping, get distance in cm and print result (0 = outside set distance range)
    // Serial.print(" cm");

    if (input == 0) {  // if ultrasonic cannot detect an object, then it will say 0 cm.
      drive_break();
    } else {
      myController.compute();

      // Serial.print(" - ");
      // Serial.print(output);
      // Serial.println(" pwm");

      if (output > 0) {
        if (output < minOutput) {
          output = minOutput;
        }
        drive_forward(output, output);
      } else {
        if (output > -minOutput) {
          output = -minOutput;
        }
        drive_backwards(-output, -output);
      }
    }
    myController.debug(&Serial, "myController", PRINT_INPUT |     // Can include or comment out any of these terms to print
                                                  PRINT_OUTPUT |  // in the Serial plotter
                                                  PRINT_SETPOINT | PRINT_BIAS | PRINT_P | PRINT_I | PRINT_D);

    timer = millis();
  }
}