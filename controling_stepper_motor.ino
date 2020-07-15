// include the Arduino Library
#include <Stepper.h>

// Define Constants

// Number of steps per output rotation
const int STEPS_PER_REV = 200;
const int SPEED_CONTROL = A0;

// create Instance of Stepper Class
// Specify pins used for motor coils
// The pins used are 8,9,10,11
// Connected to L298N Motor Driver In1, In2, In3, In4
// pins entered in sequnece 1-2-3-4 for proper step sequncing

Stepper stepper_NEMA17(STEPS_PER_REV, 8, 9, 10, 11);

void setup() {
  //nothing to do inside the setup
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(SPEED_CONTROL);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if(motorSpeed > 0){
    stepper_NEMA17.setSpeed(motorSpeed);
    // step 1/100 of a revaloution:
    stepper_NEMA17.step(STEPS_PER_REV / 100);
  }

}
