#define WHITE 24
#define RED 26
#define BLUE 28
#define YELLOW 30
#define READ A0
#define THRESHOLD 50

void setup() {
  // put your setup code here, to run once:
  pinMode(WHITE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(READ, INPUT);
  Serial.begin(19200);
}

void resetLEDs(){
  digitalWrite(WHITE, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(YELLOW, LOW);
}

bool isWithin(int value, int threshold, int target){
  return (value > (target - threshold)) && (value < (target + threshold));
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(READ));
  resetLEDs();
  if (isWithin(analogRead(READ), THRESHOLD, 210)){
    digitalWrite(YELLOW, HIGH);
  }
  else if (isWithin(analogRead(READ), THRESHOLD, 673)){
    digitalWrite(BLUE, HIGH);
  }
  else if (isWithin(analogRead(READ), THRESHOLD, 808)){
    digitalWrite(WHITE, HIGH);
  }
  else {
    digitalWrite(RED, HIGH);
  }
  delay(100);
}
