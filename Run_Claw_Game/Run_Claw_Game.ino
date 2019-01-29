/* Claw Game Execution program. Takes joystick and button input to move claw in 3 axes
 *     and close/open claw
 * Authors: Wisconsin Robotics 2018 Outreach Robotics: Tanner Wolf, Jeremy Itan, Ian Hogenkamp
 */

// Libraries to add?
// Will we be using I2C? If so the wire library will likely be needed

//Indices for motors in motor controller arrays
#define MTR_X 0
#define MTR_Y 1
#define MTR_Z 2
#define MTR_CLAW 3

// Global variables
const int lim_x_max = 2;
const int lim_x_min = 3;
const int lim_y_max = 4;
const int lim_y_min = 5;

// Limit checking variables
//Origin defined as ( x_min , y_min )
bool x_max_reached = false;
bool x_min_reached = false;
bool y_max_reached = false;
bool y_min_reached = false;

//Motor arduino pins (pending, arduino mega may have different arragement of pins)
int mtrPinA[4] = {54, 55, 62, 63}; // INA: Clockwise input for motors
int mtrPinB[4] = {56, 57, 64, 65}; // INB: Counter-clockwise input for motors
int pwmPin[4] = {2, 3, 4, 5}; // PWM input for motors
int cspin[4] = {58, 59, 66, 67}; // CS Current sense ANALOG input for motors
int enpin[4] = {60, 61, 68, 69}; // EN: Status of switches output (Analog pin) for motors

void setup() {
  // Initialize pins
  pinMode(lim_x_max, INPUT_PULLUP);
  pinMode(lim_x_min, INPUT_PULLUP);
  pinMode(lim_y_max, INPUT_PULLUP);
  pinMode(lim_y_min, INPUT_PULLUP);
  // Move x-y to origin (function/method call?)
  moveToOrigin();
  // Retract Claw
}

void loop() {
  
  // Check controller input
  int input_left = 0;
  int input_right = 0;
  readInput();
  // Set x-y motor movement
      // Check limit switches
      // Set motor controller values

  // How to handle drop, home?
      // Option 1: If drop button pressed: drop, close, lift, home, open
      // Option 2: controller to manually drop/lift, close/open, then a home and release button?

}

//Function idea: Call before sending commands to motors to check to see if any limit switches are being tripped.
void checkLimits(){
    x_max_reached = (digitalRead(lim_x_max)==HIGH) ? true : false;
    x_min_reached = (digitalRead(lim_x_min)==HIGH) ? true : false;
    y_max_reached = (digitalRead(lim_y_max)==HIGH) ? true : false;
    y_min_reached = (digitalRead(lim_y_min)==HIGH) ? true : false;
}

//Function to move claw to origin. This could be replaced with a more broad move claw function that takes in a parameter
void moveToOrigin(){ 
  checkLimits();
  while (!(x_min_reached && y_min_reached)){
    if(!x_min_reached){
      // check if motors are running?
      // function(s) to start motors to move claw toward origin on x axis
    } else {
      // check if motor running?
      stopMotor(MTR_X);
    }
    if(!y_min_reached){
      //function(s) to start motors to move claw toward origin on y axis
    } else {
      //check if motor running?
      stopMotor(MTR_Y);
    }
    checkLimits();
  };
}

void runMotors() {

  
}

void readInput() {
  
}

void stopMotor(int motor) {
  digitalWrite(mtrPinA[motor], LOW);
  digitalWrite(mtrPinB[motor], LOW);
  analogWrite(pwmPin[motor], 0);
}
