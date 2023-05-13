#define motor_R1 9
#define motor_R2 8
#define motor_L1 6
#define motor_L2 7
#define EnR 11
#define EnL 10

int Sen0 = A5;
int Sen1 = A4;
int Sen2 = A3;
int Sen3 = A2;
int Sen4 = A1;
int Sen5 = A0;
int Sen6 = 4;
int Sen7 = 5;
int Weights[8]={-30, -20, -15, -5, 5, 15, 20, 30};
int S[8];

int speed=255;
float Kp= 8;
float Ki=0;
float Kd=20;
float maxSpeed = 120;

int error_dir=0;

int position_error=0;
int I=0;
int last_error=0;

int turn_direction = 0;

void setup() {
  Serial.begin(9600);

  pinMode(motor_R1, OUTPUT);
  pinMode(motor_R2, OUTPUT);
  pinMode(motor_L1, OUTPUT);
  pinMode(motor_L2, OUTPUT);

  pinMode(Sen0, INPUT);
  pinMode(Sen1, INPUT);
  pinMode(Sen2, INPUT);
  pinMode(Sen3, INPUT);
  pinMode(Sen4, INPUT);
  pinMode(Sen5, INPUT);
  pinMode(Sen6, INPUT);
  pinMode(Sen7, INPUT);

}


void ReadSensor()
{
  S[0]=digitalRead(A5);
  S[1]=digitalRead(A4);
  S[2]=digitalRead(A3);
  S[3]=digitalRead(A2);
  S[4]=digitalRead(A1);
  S[5]=digitalRead(A0);
  S[6]=digitalRead(4);
  S[7]=digitalRead(5);
  // Serial.print(S[0]+"---");
  // Serial.print(S[1]+"---");
  // Serial.print(S[2]+"---");
  // Serial.print(S[3]+"---");
  // Serial.print(S[4]+"---");
  // Serial.print(S[5]+"---");
  // Serial.print(S[6]+"---");
  // Serial.println(S[7]);
  turn_direction=0;
  if(S[0]==0 && S[1]==0)
  turn_direction = -1;
  if(S[7]==0 && S[6]==0)
  turn_direction = 1;
}
void error()
{
  int position_error = 0;
  for (int i = 0; i < 8; i++) {
    position_error += S[i] * Weights[i]; //s[1]=1*-15=-15
  }
  // Serial.print(position_error);
  //   Serial.print("---");
    PID_Calc(position_error);
    if(position_error>0 || position_error <0)
    error_dir=position_error;
}



void PID_Calc(int error)
{
  float P_turn=Kp*error; //225
  float D_adjust=Kd*(error-last_error);
   //float Integral=Ki*(I+error);
//   float PID= P_Turn+Integral+Derivative;
  float PID=P_turn+D_adjust;
last_error=error;
/*if((S[0]==0 && S[1]==1 && S[2]==1 && S[3]==0 && S[4]==0 && S[5]==0 && S[6]==0 && S[7]==0) || 
  (S[0]==0 && S[1]==0 && S[2]==1 && S[3]==1 && S[4]==0 && S[5]==0 && S[6]==0 && S[7]==0) || 
  (S[0]==0 && S[1]==0 && S[2]==0 && S[3]==1 && S[4]==1 && S[5]==0 && S[6]==0 && S[7]==0) ||
  (S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0 && S[4]==1 && S[5]==1 && S[6]==0 && S[7]==0) ||
  (S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0 && S[4]==0 && S[5]==1 && S[6]==1 && S[7]==0)
  { //Black surface, white line.*/
    float  right_speed=speed - PID; //Change the polarity of P_turn if required.
    float  left_speed=speed + PID;
  /*}
  else if(((S[0]==1 && S[1]==0 && S[2]==0 && S[3]==1 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1) ||  
          (S[0]==1 && S[1]==1 && S[2]==0 && S[3]==0 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1) || 
          (S[0]==1 && S[1]==1 && S[2]==1 && S[3]==0 && S[4]==0 && S[5]==1 && S[6]==1 && S[7]==1) ||
          (S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==0 && S[5]==0 && S[6]==1 && S[7]==1) ||
          (S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==1 && S[5]==0 && S[6]==0 && S[7]==1))
          { //White surface, black line.
    float right_speed=speed+P_turn; //Chnage the polarity of P_turn if required.
    float left_speed=speed-P_turn;
  }*/

if(left_speed > maxSpeed)
left_speed = maxSpeed;
if(right_speed > maxSpeed)
right_speed = maxSpeed;
if(left_speed < -maxSpeed)
left_speed = -maxSpeed;
if(right_speed < -maxSpeed)
right_speed = -maxSpeed;

// Serial.print(left_speed);
// Serial.print("---");
// Serial.print(right_speed);
// Serial.print("---");
// Serial.println(P_turn);
//Serial.print("---");
//Serial.println(PID);
rotateMotor(right_speed, left_speed);
}

void rotateMotor(float rightMotorSpeed, float leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(motor_R1,LOW);
    digitalWrite(motor_R2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(motor_R1,HIGH);
    digitalWrite(motor_R2,LOW);      
  }
  else
  {
    digitalWrite(motor_R1,LOW);
    digitalWrite(motor_R2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(motor_L1,LOW);
    digitalWrite(motor_L2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(motor_L1,HIGH);
    digitalWrite(motor_L2,LOW);      
  }
  else 
  {
    digitalWrite(motor_L1,LOW);
    digitalWrite(motor_L2,LOW);      
  }

  if(turn_direction == 1){
    // right
    digitalWrite(motor_L1,HIGH);
    digitalWrite(motor_L2, LOW);
    digitalWrite(motor_R1,LOW);
    digitalWrite(motor_R2,HIGH);
    rightMotorSpeed = 100;
    leftMotorSpeed = 100;
  }

  if(turn_direction == -1){
    // left
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, HIGH);
    digitalWrite(motor_R1, HIGH);
    digitalWrite(motor_R2, LOW);
    rightMotorSpeed = 100;
    leftMotorSpeed = 100;
  }
  analogWrite(EnR, abs(rightMotorSpeed));
  analogWrite(EnL, abs(leftMotorSpeed));    
}

void loop() {
  // put your main code here, to run repeatedly:  
  ReadSensor();
  error();
  //PID_Calc();
  if(S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1)
  {
    //digitalWrite(7, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    //digitalWrite(7, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  // if(S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1)
  // {
  //   rotateMotor(1, 1);
  //   delay(2000);
  //   //digitalWrite(7, HIGH);
  //   digitalWrite(LED_BUILTIN, HIGH);
  //   delay(200);
  //   digitalWrite(LED_BUILTIN, LOW);
  //   //digitalWrite(7, LOW);
  // }
  
  //if(S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1)
  //{
      //if(S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1)
      //{
        // while(S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1){
          
        //   Serial.println(error_dir);
        // }
        while(S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1) {
          ReadSensor();
          OutofLine(error_dir);
        }
      //}
  //}
}

  // if(S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1)
  // {
  //   rotateMotor(-50,70);
  // }

  // if(S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==0 && S[5]==0 && S[6]==0 && S[7]==0)
  // {
  //   rotateMotor(70,-50);
  // }
  
  // if(S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0 && S[4]==0 && S[5]==1 && S[6]==1 && S[7]==1)
  // {
  //   rotateMotor(-50,70);
  // }

  // if(S[0]==1 && S[1]==1 && S[2]==1 && S[3]==0 && S[4]==0 && S[5]==0 && S[6]==0 && S[7]==0)
  // {
  //   rotateMotor(70,-50);
  // }
  // if(S[0]==1 && S[1]==1 && S[2]==1 && S[3]==1 && S[4]==0 && S[5]==0 && S[6]==0 && S[7]==0)
  // {
  //   rotateMotor(70,-50);
  // }
  // if(S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0 && S[4]==1 && S[5]==1 && S[6]==1 && S[7]==1)
  // {
  //   rotateMotor(-50,70);
  // }

  // if(S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0 && S[4]==0 && S[5]==0 && S[6]==1 && S[7]==1)
  // {
  //   rotateMotor(70,-50);
  // }

  // if(S[0]==1 && S[1]==1 && S[2]==0 && S[3]==0 && S[4]==0 && S[5]==0 && S[6]==0 && S[7]==0)
  // {
  //   rotateMotor(-50,70);
  // }

  // if(S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0 && S[4]==0 && S[5]==0 && S[6]==0 && S[7]==0)
  // {
  //   rotateMotor(0,0);
  // }
void OutofLine(int turn)
{
  Serial.println("---");
  PID_Calc(-turn);
}
