// Right Motor
int enableRightMotor = 11;
int rightMotorPin1 = 9;
int rightMotorPin2 = 8;

// Left Motor
int enableLeftMotor = 10;
int leftMotorPin1 = 7;
int leftMotorPin2 = 6;

// IR Sensors
int irSensorPin1 = 5;
int irSensorPin2 = 4;
int irSensorPin3 = A0;
int irSensorPin4 = A1;
int irSensorPin5 = A2;
int irSensorPin6 = A3;
int irSensorPin7 = A4;
int irSensorPin8 = A5;

// LED Sensor
int ledPin = 13;

//Speed
int speed = 50;

void setup() {
  // Right Motor
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  // Left Motor
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // IR Sensor
  pinMode(irSensorPin1, INPUT);
  pinMode(irSensorPin2, INPUT);
  pinMode(irSensorPin3, INPUT);
  pinMode(irSensorPin4, INPUT);
  pinMode(irSensorPin5, INPUT);
  pinMode(irSensorPin6, INPUT);
  pinMode(irSensorPin7, INPUT);
  pinMode(irSensorPin8, INPUT);

  // LED Pin
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int irSensorValue1 = analogRead(irSensorPin1);
  int irSensorValue2 = analogRead(irSensorPin2);
  int irSensorValue3 = digitalRead(irSensorPin3);
  int irSensorValue4 = digitalRead(irSensorPin4);
  int irSensorValue5 = digitalRead(irSensorPin5);
  int irSensorValue6 = digitalRead(irSensorPin6);
  int irSensorValue7 = digitalRead(irSensorPin7);
  int irSensorValue8 = digitalRead(irSensorPin8);

  // Moving Forward
  if((irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
    (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == HIGH && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
    (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == HIGH && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW)) {
            digitalWrite(rightMotorPin1, HIGH);
            digitalWrite(rightMotorPin2, LOW);
            digitalWrite(leftMotorPin1, LOW);
            digitalWrite(leftMotorPin2, HIGH);

            analogWrite(enableRightMotor, speed);
            analogWrite(enableLeftMotor, speed);
  }

  // Moving Right
  else if((irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == HIGH && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == HIGH && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == HIGH) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == HIGH && irSensorValue6 == LOW && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == HIGH && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == HIGH) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == HIGH && irSensorValue7 == LOW && irSensorValue8 == HIGH) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == HIGH && irSensorValue8 == HIGH) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == LOW && irSensorValue8 == HIGH) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == HIGH && irSensorValue6 == LOW && irSensorValue7 == HIGH && irSensorValue8 == HIGH) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == HIGH) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == HIGH) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == HIGH)) {
            digitalWrite(rightMotorPin1, LOW);
            digitalWrite(rightMotorPin2, HIGH);
            digitalWrite(leftMotorPin1, LOW);
            digitalWrite(leftMotorPin2, HIGH);

            analogWrite(enableRightMotor, 60);
            analogWrite(enableLeftMotor, 60);
  }

  // Moving Left
  else if((irSensorValue1 == HIGH && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == HIGH && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == HIGH && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == HIGH && irSensorValue2 == HIGH && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == HIGH && irSensorValue2 == LOW && irSensorValue3 == HIGH && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == HIGH && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == HIGH && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == LOW && irSensorValue4 == HIGH && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == HIGH && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == HIGH && irSensorValue2 == HIGH && irSensorValue3 == LOW && irSensorValue4 == HIGH && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == HIGH && irSensorValue2 == LOW && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == HIGH && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == HIGH && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW)) {
            digitalWrite(rightMotorPin1, HIGH);
            digitalWrite(rightMotorPin2, LOW);
            digitalWrite(leftMotorPin1, HIGH);
            digitalWrite(leftMotorPin2, LOW);

            analogWrite(enableRightMotor, speed);
            analogWrite(enableLeftMotor, speed);
  }

  // Checkpoint Blink and Stop
  else if((irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
          (irSensorValue1 == HIGH && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
          (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == HIGH) ||
          (irSensorValue1 == HIGH && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == HIGH)) {

            // lED Blinks
            digitalWrite(ledPin, HIGH);
            delay(200);
            digitalWrite(ledPin, LOW);
            delay(200);

            // Moves Forward to check if the line is a Checkpoint or not
            digitalWrite(rightMotorPin1, HIGH);
            digitalWrite(rightMotorPin2, LOW);
            digitalWrite(leftMotorPin1, LOW);
            digitalWrite(leftMotorPin2, HIGH);

            analogWrite(enableRightMotor, speed);
            analogWrite(enableLeftMotor, speed);

            delay(100);

            // Stops
            if((irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
              (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == LOW && irSensorValue8 == LOW) ||
              (irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
              (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
              (irSensorValue1 == HIGH && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == LOW) ||
              (irSensorValue1 == LOW && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == HIGH) ||
              (irSensorValue1 == HIGH && irSensorValue2 == HIGH && irSensorValue3 == HIGH && irSensorValue4 == HIGH && irSensorValue5 == HIGH && irSensorValue6 == HIGH && irSensorValue7 == HIGH && irSensorValue8 == HIGH)) {
                  digitalWrite(ledPin, HIGH);
                  delay(80);
                  digitalWrite(ledPin, LOW);
                  delay(80);
                  digitalWrite(ledPin, HIGH);
                  delay(80);
                  digitalWrite(ledPin, LOW);
                  delay(80);

                  digitalWrite(rightMotorPin1, LOW);
                  digitalWrite(rightMotorPin2, LOW);
                  digitalWrite(leftMotorPin1, LOW);
                  digitalWrite(leftMotorPin2, LOW);

                  analogWrite(enableRightMotor, 0);
                  analogWrite(enableLeftMotor, 0);
              }
    }

    // White Space
    else if(irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) {
            // Moves Forward
            digitalWrite(rightMotorPin1, HIGH);
            digitalWrite(rightMotorPin2, LOW);
            digitalWrite(leftMotorPin1, LOW);
            digitalWrite(leftMotorPin2, HIGH);

            analogWrite(enableRightMotor, speed);
            analogWrite(enableLeftMotor, speed);

            delay(200);

            // If White Patch continues then Stops
            if(irSensorValue1 == LOW && irSensorValue2 == LOW && irSensorValue3 == LOW && irSensorValue4 == LOW && irSensorValue5 == LOW && irSensorValue6 == LOW && irSensorValue7 == LOW && irSensorValue8 == LOW) {
              // Moves Backword
              digitalWrite(rightMotorPin1, LOW);
              digitalWrite(rightMotorPin2, HIGH);
              digitalWrite(leftMotorPin1, HIGH);
              digitalWrite(leftMotorPin2, LOW);

              analogWrite(enableRightMotor, speed);
              analogWrite(enableLeftMotor, speed);

              delay(150);

              // Stops
              digitalWrite(rightMotorPin1, LOW);
              digitalWrite(rightMotorPin2, LOW);
              digitalWrite(leftMotorPin1, LOW);
              digitalWrite(leftMotorPin2, LOW);

              analogWrite(enableRightMotor, 0);
              analogWrite(enableLeftMotor, 0);
            }
    }
    
    else {
      digitalWrite(rightMotorPin1, HIGH);
      digitalWrite(rightMotorPin2, LOW);
      digitalWrite(leftMotorPin1, LOW);
      digitalWrite(leftMotorPin2, HIGH);

      analogWrite(enableRightMotor, speed);
      analogWrite(enableLeftMotor, speed);

      /**
      digitalWrite(rightMotorPin1, LOW);
      digitalWrite(rightMotorPin2, LOW);
      digitalWrite(leftMotorPin1, LOW);
      digitalWrite(leftMotorPin2, LOW);

      analogWrite(enableRightMotor, 0);
      analogWrite(enableLeftMotor, 0);
      */
    }
}
