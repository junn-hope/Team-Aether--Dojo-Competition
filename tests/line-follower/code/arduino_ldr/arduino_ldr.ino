

int right_ir = A1;
int left_ir = A2;
int front_ir = A3;

int right_val, left_val, front_val;

#define DELAY 300 

void setup() {
  // put your setup code here, to run once:
  pinMode(right_ir, INPUT);
  pinMode(left_ir,INPUT);
  pinMode(front_ir,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  right_val = digitalRead(right_ir);
  left_val = digitalRead(left_ir);
  front_val = digitalRead(front_ir);

  if((right_val == 1) && (left_val == 0)){
    // steer to the left
    Serial.println("Left");
  } else if((right_val == 0) && (left_val == 1)){
    // steer to the right
    Serial.println("Right");
  } else if((right_val == 1) && (left_val == 1)){
    Serial.println("Forward"); 
  } else if(((right_val == 0) && (left_val == 0)) && (front_val == 0)){
    // CROSSROAD: Continue moving forward
    Serial.println("Forward");
  }

  delay(DELAY);
 
}
