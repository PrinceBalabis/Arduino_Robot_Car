#include <NewPing.h>

#define TRIGGER_PIN 3
#define ECHO_PIN 2
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.

unsigned long read_ultrasonic() {
    unsigned long distance = sonar.ping_cm();
    return distance;
}
