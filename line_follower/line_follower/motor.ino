const int right_motor_a_pin = 7;     //IN1
const int right_motor_b_pin = 6;     //IN2
const int right_motor_pwm_pin = 11;  //ENA

const int left_motor_c_pin = 5;     //IN3
const int left_motor_d_pin = 4;     //IN4
const int left_motor_pwm_pin = 10;  //ENB

void setup_motors() {
  pinMode(right_motor_a_pin, OUTPUT);
  digitalWrite(right_motor_a_pin, LOW);
  pinMode(right_motor_b_pin, OUTPUT);
  digitalWrite(right_motor_b_pin, LOW);
  pinMode(right_motor_pwm_pin, OUTPUT);
  analogWrite(right_motor_pwm_pin, 0);

  pinMode(left_motor_c_pin, OUTPUT);
  digitalWrite(left_motor_c_pin, LOW);
  pinMode(left_motor_d_pin, OUTPUT);
  digitalWrite(left_motor_d_pin, LOW);
  pinMode(left_motor_pwm_pin, OUTPUT);
  analogWrite(left_motor_pwm_pin, 0);
}

// 0-255
void drive_forward(int left_motor_pwm, int right_motor_pwm) {
  digitalWrite(right_motor_a_pin, HIGH);
  digitalWrite(left_motor_c_pin, HIGH);
  digitalWrite(right_motor_b_pin, LOW);
  digitalWrite(left_motor_d_pin, LOW);

  analogWrite(right_motor_pwm_pin, right_motor_pwm);
  analogWrite(left_motor_pwm_pin, left_motor_pwm);
}

// 0-255
void drive_backwards(int left_motor_pwm, int right_motor_pwm) {
  digitalWrite(right_motor_b_pin, HIGH);
  digitalWrite(left_motor_d_pin, HIGH);
  digitalWrite(right_motor_a_pin, LOW);
  digitalWrite(left_motor_c_pin, LOW);

  analogWrite(right_motor_pwm_pin, right_motor_pwm);
  analogWrite(left_motor_pwm_pin, left_motor_pwm);
}

void drive_break() {
  digitalWrite(right_motor_b_pin, HIGH);
  digitalWrite(left_motor_d_pin, HIGH);
  digitalWrite(right_motor_a_pin, HIGH);
  digitalWrite(left_motor_c_pin, HIGH);

  analogWrite(right_motor_pwm_pin, 0);
  analogWrite(left_motor_pwm_pin, 0);
}