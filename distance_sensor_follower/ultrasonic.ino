#include <NewPing.h>

#define trigPin 3
#define echoPin 2
#define MAX_DISTANCE 200                        // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.

void setup_ultrasonic() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


unsigned long read_ultrasonic() {
    unsigned long distance = sonar.ping_cm();
    return distance;
}
