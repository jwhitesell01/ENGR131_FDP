//motorCW(int motor)
//motorCCW(int motor)
//motor: determines motor (0=m1, 1=m2)

void gateOpen() {
  Serial.println("Gates are opening.");
  motorCCW(0);
  motorCW(1);
}
void gateClose() {
  Serial.println("Gates are closing.");
  motorCW(0);
  motorCCW(1);
}
