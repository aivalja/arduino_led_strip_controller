//Code created by Ian Buckley for an article on makeuseof.com


//define pins for the red, green and blue LEDs
#define RED_LED 9
#define BLUE_LED 10
#define GREEN_LED 6
#define WHITE_LED 3
#define WARM_WHITE_LED 5
#define RED_POT 0
#define GREEN_POT 1
#define BLUE_POT 2
#define WHITE_POT 3
#define BUTTON 2

//overall brightness value
int brightness = 255;
//individual brightness values for the red, green and blue LEDs
int gBright = 0; 
int rBright = 0;
int bBright = 0;
int wBright = 0;
int wwBright = 0;

int fadeSpeed = 10;
int button = 0;
int oldButton = 0;
int whiteOn = 0;

void setup() {
  //set up pins to output.
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(WARM_WHITE_LED, OUTPUT);
  pinMode(BUTTON, INPUT);

//Call the TurnOn method, wait, then call TurnOff
//TurnOn();
//delay(5000);
//TurnOff();
}

int getButton(){
  if(digitalRead(BUTTON) == HIGH && button == oldButton) { //If Pin 2 is high (At 5 Volts)
    button = 1 - button; //If Button is set as 0 then Button = 1 - 0 (=1) and if Button is 1 then Button=1 - 1 (=0)
  }

  if(digitalRead(BUTTON) == LOW && button != oldButton){
    oldButton = button;
  }
  if(button == 1 && oldButton == 0) { //If Button is 1 and OldButton is 0 (This means basically means "If the button was just pressed"
      //Put what you want to happen when the "Switch" is on here
  }
  
  if(button == 0 && oldButton == 1) {
    //Put what you want to happen when the "Switch" is off here
  }

  //oldButton = button; //The data is now old
  return button;
}

void setValues(int red, int green, int blue, int white, int warm_white){
  analogWrite(RED_LED, red);
  analogWrite(GREEN_LED, green);
  analogWrite(BLUE_LED, blue);
  analogWrite(WHITE_LED, white);
  analogWrite(WARM_WHITE_LED, warm_white);
}

int readRed(){
  return floor(analogRead(RED_POT)/1023.0*255);
}

int readGreen(){
  return floor(analogRead(GREEN_POT)/1023.0*255);
}

int readBlue(){
  return floor(analogRead(BLUE_POT)/1023.0*255);
}

int readWhite(){
  return floor(analogRead(WHITE_POT)/1023.0*255);
}

// if white potentiometer at max, no warm white and vice versa
int readWarmWhite(){
  return floor((1023-analogRead(WHITE_POT))/1023.0*255);
}

void loop(){
  whiteOn = getButton();
  setValues(readRed(),readGreen(),readBlue(),readWhite()*whiteOn,readWarmWhite()*whiteOn);
  delay(10);
}
