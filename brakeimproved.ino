unsigned long brakeTimer = 0;
int brakeAverage = 1850;
int brakeThreshold = 50;
int spikeAvg [10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool brakebrake;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  for (int i = 0; i < 9; i++) {
    spikeAvg[i + 1] = spikeAvg[i];
  }
  spikeAvg[0] = analogRead(A0);
  int sum;
  for (int i; i < 10; i++) {
    sum =+ spikeAvg[i];
  }
  sum = sum / 10;

  if ((sum * 9.75 - brakeAverage > brakeThreshold)) {
    if (millis() - brakeTimer > 10) {
    brakebrake = true;
    brakeTimer = millis();
    }
  }
  else {
    //if (millis() - brakeTimer > 20) {
      brakebrake = false;
    //}
  }
  Serial.print(1500);
  Serial.print("  ");
  Serial.print(1500 + brakebrake * 100);
  Serial.print("  ");
  Serial.print(sum);
  Serial.print("  ");
  Serial.println(analogRead(A0));
}

