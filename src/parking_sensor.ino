#define TRIG 7
#define ECHO 8
#define GREEN 13
#define RED 12
#define BEEP 10
// defining pin numbers for ease of code


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      // Starting serial monitor
  pinMode(TRIG, OUTPUT);   // TRIG sends the sound pulse
  pinMode(ECHO, INPUT);    // ECHO receives the returning pulse
  pinMode(GREEN, OUTPUT);  // setting outputs
  pinMode(RED, OUTPUT);
  pinMode(BEEP, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, LOW);       // Make sure TRIG starts LOW
  delayMicroseconds(2);          // Small pause
  digitalWrite(TRIG, HIGH);      // Send HIGH for 10 microseconds
  delayMicroseconds(10);       
  digitalWrite(TRIG, LOW);       // Turn TRIG off again

  // measure how long the wave takes to return, and store in duration variable
  long duration = pulseIn(ECHO, HIGH);

  // convert value in duration to distance using speed of sound
  long distance = duration * 0.034 / 2;

  Serial.println(distance);

  // conditionals based on distance
  if (distance < 5) {
    // if very close, show red and beep
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    
    digitalWrite(BEEP, HIGH);
    delay(500);
    digitalWrite(BEEP, LOW);
    delay(500);
  } 
  else if (distance < 9) {
    // if close but not too close, solely show red
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    
  } 
  else {
    // if safe distance, show green
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BEEP, LOW);
  }

  // tiny pause to stabilize sensor readings 
  delay(250); 
}


