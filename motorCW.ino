//'motor' is to choose the motor
// 0 = motor1
// 1 = motor2
//'tim' is to declare how long to run the motor

void motorCW(int motor) {
  //Runs motor clockwise, spin right
  if ( motor == 0 ) {
    digitalWrite(motor1a, HIGH);
    digitalWrite(motor1b, LOW);
    Serial.println("Motor 1 closed.");
  } else if ( motor == 1 ) {
    digitalWrite(motor2a, HIGH);
    digitalWrite(motor2b, LOW);
    Serial.println("Motor 2 opened.\n");
  }
  delay(motorTime); // how long to run each motor
  motorStop();
}
