/*  Used code from Instructables for motor controll
   >> How to Use the L293D Motor Driver - Arduino Tutorial
   >> By codebender_cc
   >>
   >> URL:
   >> https://www.instructables.com/id/How-to-use-the-L293D-Motor-Driver-Arduino-Tutorial/
*/

//Testing out GitHub PUSH

//L293D
//Motor 1
const int motor1a  = 40; // pin 14 of L293
const int motor1b  = 39; // pin 10 of L293
//Motor 2
const int motor2a  = 36; // pin  7 of L293
const int motor2b  = 35; // pin  2 of L293

//Light Sensor
const int sensor = 24; // port J6 on Booster Board
int newSensor_data; // meant to adjust how much data is sent through serial
int oldSensor_data; // "    "
int sdThresh = 550; // adjusts where to start the program, also for the green led signal program

//Code timings/logic
const int motorTime = 1250; // determines how long to run each motor, milli seconds
const int gateTime = 25000; // determines how long to wait between open/close, milli seconds
unsigned long prevMillis = 0;// needed for timing
bool gatePos = false; // open = true, closed = false

void setup() {
  //Setup serial comm port
  Serial.begin(19200);
  Serial.println("Program initiated.\n");

  //Set motor pins as outputs
  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);

  //Set sensor pins as inputs
  pinMode(sensor, INPUT);

  //Quick runthrough
  delay(2500);
  gateOpen();
  delay(2500);
  gateClose();

  Serial.println("Program initiation complete.");
  Serial.println();
}

void loop() {
  newSensor_data = analogRead(sensor);
  unsigned long currMillis = millis();

  if ( newSensor_data >= sdThresh ) { //checks if sensor has passed threshhold
    if ( gatePos == false ) {  //checks if gate is closed
      Serial.print("Sensor data: ");
      Serial.println(newSensor_data);
      prevMillis = millis(); // restarts the "timer"
      gateOpen();
      gatePos = true; // tells itself gate is now open
    }
  }
  if ( currMillis - prevMillis >= gateTime ) { //waits to close gates
    prevMillis = currMillis; // restarts the "timer"
    if ( gatePos == true ) { //checks if gate is open
      gateClose(); //closes gates, takes 2.5 sec to close
      gatePos = false;
    }
  }
  //Serial.print(gatePos);
}
