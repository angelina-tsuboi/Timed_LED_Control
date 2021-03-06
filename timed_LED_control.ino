const int red = 2;
const int yellow = 3;
const int blue = 4;
const int green = 5;
const int intervalPot = A0;
const int amountPot = A1;

//variables
int intervalValue; //interval of time when lights shine
int amountValue; //amount of lights shining at each interval
int value = 0; //num of light groups shining

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(intervalPot, INPUT); // potentiometer input values
  pinMode(amountPot, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  intervalValue = analogRead(intervalPot); //recieving inputs from pots
  amountValue = analogRead(amountPot);
  intervalValue = map(intervalValue, 0, 1023, 0, 255) * 50; //Map value 0-1023 to 0-255 (PWM)
  amountValue = map(amountValue, 0, 1023, 0, 255); 
  updateLED(0);
  delay(intervalValue);
  updateLED(lightAmountValue(amountValue));
  delay(intervalValue);
}

void updateLED(int amount){
  for(int i = 0; i < 4; i++){ //loops through sections
    if(i < amount){
      digitalWrite(i + 2, HIGH);
     }else{
      digitalWrite(i + 2, LOW);
     }
   }
}

int lightAmountValue(int amount){
  if(amount < 64) return 1;
  if(amount >= 64 && amount < 128) return 2;
  if(amount >= 128 && amount < 192) return 3;
  if(amount > 192) return 4;
}
