
int left_ir = A0;
int right_ir = A1;

int right_val, left_val;

// motor pins
// motor A connections
//int enA = 9;
int in1 = 2;
int in2 = 3;

// motor B connections
//int enB = 7;
int in3 = 4;
int in4 = 6;

#define DELAY 300 

// motor drive functions
void on(){
  // all motors on
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // left motor off
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void off(){
  // right motor off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // left motor off
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void moveForward(){

  // right motor on
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
  on();
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
  pinMode(right_ir, INPUT);
  pinMode(left_ir,INPUT);
 
  // motor pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  right_val = digitalRead(right_ir);
  left_val = digitalRead(left_ir);

  if((right_val == 1) && (left_val == 0)){
    // steer to the left
    Serial.println("turn right");
    //turnLeft();
  }
  
  else if((right_val == 0) && (left_val == 1)){
    // steer to the right
    Serial.println("turn left");
    //turnRight();
  }
  
  else if((right_val == 1) && (left_val == 1)){
    Serial.println("move Forward");
    //moveForward(); 
  } 
  
  else if((right_val == 0) && (left_val == 0)){
    Serial.println("move Forward");
    //moveForward(); 
  } 

}
