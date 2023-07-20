// Tuning PID: https://robotresearchlab.com/2019/02/16/pid-line-follower-tuning/


#include "ArduPID.h"

ArduPID myController;

double input = 0;
double output = 0;

// Arbitrary setpoint and gains - adjust these as fit for your project:
double setpoint = 4;
double p = 63;
double i = 0;
double d = 0;

double baseSpeed = 200;  // The minimum output to send (plus or minus)
double maxSpeed = 255;
double motorSpeedLeft = 0, motorSpeedRight = 0;

unsigned long timer = 0;
unsigned long timerInterval = 50;  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.

void setup_pid() {
  myController.begin(&input, &output, &setpoint, p, i, d);
  //myController.reverse();
  myController.setSampleTime(10);  // OPTIONAL - will ensure at least 10ms have past between successful compute() calls
  myController.setOutputLimits(-maxSpeed, maxSpeed);
  myController.setBias(0);
  //myController.setWindUpLimits(-10, 10); // Groth bounds for the integral term to prevent integral wind-up

  myController.start();
}

void run_pid() {
  if (millis() - timer >= timerInterval) {

    read_sensor_calibrated();
    detect_black();
    calculate_middle_of_black();
    input = middleLocation;

    if (input == 0) {
      // drive slow
      drive_forward(baseSpeed, baseSpeed);
    } else {
      myController.compute();

      // Serial.print(" - ");
      // Serial.print(output);
      // Serial.println(" pwm");

      if (output < 0) {  // turn right
        motorSpeedLeft = maxSpeed;
        motorSpeedRight = maxSpeed + output;
        if (motorSpeedRight < baseSpeed) {
          motorSpeedRight = baseSpeed;
        }
        drive_forward(motorSpeedLeft, motorSpeedRight);
      } else {  // turn left
        motorSpeedLeft = maxSpeed - output;
        motorSpeedRight = maxSpeed;
        if (motorSpeedLeft < baseSpeed) {
          motorSpeedLeft = baseSpeed;
        }
        drive_forward(motorSpeedLeft, motorSpeedRight);
      }
    }
    // myController.debug(&Serial, "myController", PRINT_INPUT |     // Can include or comment out any of these terms to print
    //                                               PRINT_OUTPUT |  // in the Serial plotter
    //                                               PRINT_SETPOINT | PRINT_BIAS | PRINT_P | PRINT_I | PRINT_D);

    timer = millis();
  }
}