void setupSensorLED() {
  pinMode(76, OUTPUT); //green board led
}
void loopSensorLED() {
  if ( newSensor_data >= sdThresh ) {
    analogWrite(76, 63);
    delay(50);
    digitalWrite(76, LOW);
    delay(50);
  }
}
