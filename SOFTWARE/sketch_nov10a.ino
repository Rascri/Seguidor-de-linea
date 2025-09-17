#include <QTRSensors.h>

#define Kp  // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd  // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define rightMaxSpeed 100 // max speed of the robot
#define leftMaxSpeed 100 // max speed of the robot
#define rightBaseSpeed 50 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 50  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   13     // emitter is controlled by digital pin 2

const int motorIzqIN1 = 2;
const int motorIzqIN2 = 3;
const int motorIzqPWM = 9;
const int motorDerIN1 = 4;
const int motorDerIN2 = 5;
const int motorDerPWM = 6;
const int stby = 7;

QTRSensors  qtra;
unsigned int sensorValues[NUM_SENSORS];

void setup(){
  
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A7, A6, A5, A4, A3, A2, A1, A0}, NUM_SENSORS);
  qtr.setEmitterPin(EMITTER_PIN);
  
  pinMode(motorIzqIN1, OUTPUT);
  pinMode(motorIzqIN2, OUTPUT);
  pinMode(motorIzqPWM, OUTPUT);
  pinMode(motorDerIN1, OUTPUT);
  pinMode(motorDerIN2, OUTPUT);
  pinMode(motorDerPWM, OUTPUT);
  pinMode(stby, OUTPUT);

   for (uint16_t i = 0; i < 800; i++){
      qtr.calibrate();
    }
    delay(3000); // wait to position the bot before entering the main loop 
    
    //Serial.begin(9600);
    
    digitalWrite(stby, HIGH);
    digitalWrite(motorIzqIN1, HIGH);
    digitalWrite(motorIzqIN2, LOW);
    digitalWrite(motorDerIN1, HIGH);
    digitalWrite(motorDerIN2, LOW); 
  } 

int lastError = 0;

void loop()
{

  int position = qtr.readLineBlack(sensorValues);

  unsigned int sensors[8];

  //Serial.println(position);
  //delay(700);

  int error = position - 3500;

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;
  
  if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
  if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive
  
  // move forward with appropriate speeds
    analogWrite(motorIzqPWM, leftMotorSpeed);
    analogWrite(motorDerPWM, rightMotorSpeed);
}
