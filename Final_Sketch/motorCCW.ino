//'motor' is to choose the motor
// 0 = motor1
// 1 = motor2
//'tim' is to declare how long to run the motor

void motorCCW(int motor) {
  //Runs motor counter-clockwise, spin left
  if ( motor == 0 ) {
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, HIGH);
    Serial.println("Motor 1 opened.");
  } else if ( motor == 1 ) {
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, HIGH);
    Serial.println("Motor 2 closed.\n");
  }
  delay(motorTime); // how long to run each motor
  motorStop();
}
