# Arduino_Robot_Car

## distance_sensor_follower
Could describe it as social distancing robot.
A setpoint is set in cm, default is 30cm. The robot will try to stay in that setpoint, by moving forward or reversing. In other words you can hold a hand in front of the robot, and move the hand away or towards the robot, the robot will always try to keep the right distance. The logic utilizes PID controller to smoothly control the motors based on ultrasonic sensor data.

Photo of robot:
![Photo](distance_sensor_follower/docs/robotcar.jpg?raw=true)

Video demonstration (Youtube):
[![Video demo](https://img.youtube.com/vi/vMdGYDRBIls/default.jpg)](https://www.youtube.com/watch?v=vMdGYDRBIls)


Components:
* Ultrasonic sensor HC-SR04
* Arduino Uno Rev 3
* Dual motor H-bridge L298
* 4pcs AA batteries
* Battery holder 4x AA
* Robot car kit with two DC motors and wheels
* Breadboards