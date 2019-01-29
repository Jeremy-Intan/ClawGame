/*
 * Motor control test code, WIP
 * Following example code from sparkfun here: https://github.com/sparkfun/Monster_Moto_Shield/blob/Hv12Fv10/Firmware/MonsterMoto_Shield_Example_Sketch/MonsterMoto_Shield_Example_Sketch.ino
 * Refer to this website when finding which pins correspond bewteen shields and arduino
 */
 
//Initial definitions
#define BRAKEVCC 0
#define CW 1
#define CCW 2
#define BRAKEGND 3
#define CS_THRESHOLD 100

//Indices for motors in motor controller arrays
#define MTR_X 0;
#define MTR_Y 1;
#define MTR_Z 2;
#define MTR_CLAW 3;

//Pin definitions for shields
/* VNH2SP30 pin definitions
  Not sure if we need the cs or en inputs for the feedback, but can be helpful to ensure we have output
*/
//Motor arduino pins (pending, arduino mega may have different arragement of pins)
int mtrPinA[4] = {54, 55, 62, 63}; // INA: Clockwise input for motors
int mtrPinB[4] = {56, 57, 64, 65}; // INB: Counter-clockwise input for motors
int pwmPin[4] = {2, 3, 4, 5}; // PWM input for motors
int cspin[4] = {58, 59, 66, 67}; // CS Current sense ANALOG input for motors
int enpin[4] = {60, 61, 68, 69}; // EN: Status of switches output (Analog pin) for motors

/*arduino mega pins (pending, probably dont need arrays for these pins)
*****We probably shouldnt call these C and D since A,B are the pos/neg sides of the motor connections
We could probably combine it into one array for xyz and pins for the claw (as I did -Tanner), or keep it xy in an array and z, claw alone.
*/
//int inCpin[2] = {62, 63}; //INC: Clockwise input for motors 3,4
//int inDpin[2] = {64, 65}; //IND: Counter-clockwise input for motors 3,4
//int pwmpin2[2] = {4,5}; // PWM input for motors 3,4
//int cspin2[2] = {66, 67}; // CS Current sense ANALOG input for motors 3,4
//int enpin2[2] = {68, 69}; // EN: Status of switches output (Analog pin) for motors 3,4

int statpin = 13;
int statpin2 = 14;

/*
 motorGo() will set a motor going in a specific direction
 the motor will continue going in that direction, at that speed
 until told to do otherwise.
 
 motor: this should be either 0 or 1, will selet which of the two
 motors to be controlled
 
 direct: Should be between 0 and 3, with the following result
 0: Brake to VCC
 1: Clockwise                 *May want to change this to show x/y increase or decrease instead of CW
 2: CounterClockwise
 3: Brake to GND
 
 pwm: should be a value between ? and 1023, higher the number, the faster it'll go
 * 
 * **Not sure if this is how we want to handle our inputs, but it might be fine
 */
void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm){
  if (motor <= 1){  // This will need to be changed to 3 if we use one array for all 4 motors
    if(direct <= 4){
      
      //set inA[motor]
      if(direct <=1){
        digitalWrite(mtrPinA[motor], HIGH);
      }else{
        digitalWrite(mtrPinA[motor], LOW);
      }
      
      //set inB[Motor]
      if ((direct == 0) ||(direct == 2)){
        digitalWrite(mtrPinB[motor], HIGH);
      }else{
        digitalWrite(mtrPinB[motor], LOW);
      }
      analogWrite(pwmPin[motor], pwm);
    }
  }
}

//function to stop motor movement
void motorOff(int motor){
  for (int i = 0; i < 4; i++){
    digitalWrite(mtrPinA[i], LOW);
    digitalWrite(mtrPinB[i], LOW);
  }
  analogWrite(pwmPin[motor], 0);
}

void setup() {
  Serial.begin(9600);
  pinMode(statpin, OUTPUT);
  
  //Initialize pins
  for (int i = 0; i < 4; i++){
    pinMode(mtrPinA[i], OUTPUT);
    pinMode(mtrPinB[i], OUTPUT);
    pinMode(pwmPin[i], OUTPUT);
  }
  
  //Initialize brakes
  for (int i = 0; i < 4; i++){
    digitalWrite(mtrPinA[i], LOW);
    digitalWrite(mtrPinB[i], LOW);
  }
}

void loop() {
  

}
