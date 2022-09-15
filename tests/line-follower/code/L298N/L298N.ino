// motor A connections
int enA = 9;
int in1 = 2;
int in2 = 3;

// motor B connections
int enB = 6;
int in3 = 4;
int in4 = 5;

void moveForward(){
    // right motor on
    Serial.println("Forward");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  
    // left motor on 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void turnLeft(){
   // steer the robot to the left
  // turn off the right motor, turn on the left one
  // right motor on
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // left motor off
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turnRight(){
  // steer the robot to the left
  // turn off the right motor, turn on the left one
  
  // right motor off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // left motor on
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(1);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // pin configurations
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

 // turn off all motors initially
// digitalWrite(in1, LOW);
// digitalWrite(in2, LOW);
// digitalWrite(in3, LOW);
// digitalWrite(in4, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  moveForward();
  
}

void directionControl(){
  // set the motors to run at maximum speed
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  // turn ON all motors
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(1000);

  // change motor direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(1500);

  // turn OFF all motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void speedControl(){
  // turn ON all motors
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // accelerate from 0 to maximum speed
  for(int i =0; i < 256; i++){
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(30);
  }

  // decelerate from maximum speed to 0
  for(int i = 255; i >= 255; i--){
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(30);
  }

  // turn OFF all motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
