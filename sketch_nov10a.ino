#define isBlue 1
#define isWhite 0
int c_s = 21; //D21
int l_s = 20; //D20
int ll_s = 18; //D19
int r_s = 2; //D2 
int rr_s = 3; //D3

int lm1 = 4; //pwm
int lm2 = 6; //pwm
int rm1 = 5; //pwm
int rm2 = 7; //pwm



int val = 0;
void setup() {
  
  pinMode(c_s, INPUT);
  pinMode(l_s, INPUT);
  pinMode(ll_s, INPUT);
  pinMode(r_s, INPUT);
  pinMode(rr_s, INPUT);

  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);

  Serial.begin(9600);   // sets the digital pin 13 as output

} 

  void loop() {
    while(1){
    unsigned long time = millis();
    int cs = digitalRead(c_s);  // read the input pin
    
    int rs = digitalRead(r_s);  // read the input pin
   

    int rrs = digitalRead(rr_s);  // read the input pin
   

    int ls = digitalRead(l_s);  // read the input pin
   

    int lls = digitalRead(ll_s);  // read the input pin
   
    if((cs == isBlue) && (rs == isBlue) && (rrs == isBlue) && (ls == isBlue) && (lls == isBlue)) {  // No Movement
        if((millis() - time) > 1000){
        analogWrite(lm2, 0);
        analogWrite(rm2, 0);
        analogWrite(lm1, 0);
        analogWrite(rm1, 0);
        }
    }

    if((cs == isWhite) && (rs == isBlue) && (rrs == isBlue) && (ls == isBlue) && (lls == isBlue)) {  //Move Forward
      analogWrite(rm1, 180);
      analogWrite(lm1, 180);
      time = millis();
      continue;
    }

    if(((rs == isWhite) || (rrs == isWhite)) && (ls == isBlue) && (lls == isBlue) && (cs == isBlue)) {  //Move right
      analogWrite(rm1,0);
      analogWrite(lm1, 130);
      analogWrite(lm2, 0);
      analogWrite(rm2, 80);
      time = millis();
      continue;
    }

  

    if(((ls == isWhite) || (lls == isWhite)) && (rs == isBlue) && (rrs == isBlue) && (cs == isBlue)) {   //Move Left
      analogWrite(rm1, 130);
      analogWrite(lm1, 0);
      analogWrite(lm2, 80);
      analogWrite(rm2, 0);
      time = millis();
      continue;
    }

    if((rs == isWhite) && (rrs == isWhite) && (ls == isBlue) && (lls == isBlue) && (cs == isBlue) && ((cs == isWhite) || (cs == isBlue))) {  //90 Degree on right side
      analogWrite(rm1,0);
      analogWrite(lm1, 130);
      analogWrite(lm2, 0);
      analogWrite(rm2, 80);
      time = millis();
      continue;
    }

     if((ls == isWhite) && (lls == isWhite) && (rs == isBlue) && (rrs == isBlue) && ((cs == isWhite) || (cs == isBlue))) {  //90 Degree on left side
      analogWrite(rm1, 130);
      analogWrite(lm1, 0);
      analogWrite(lm2, 80);
      analogWrite(rm2, 0);
      time = millis();
      continue;
    }

     if(((rs == isWhite) || (rrs == isWhite)) && ((ls == isWhite) || (lls == isWhite))) {   //Condition of circle or kite
      analogWrite(rm1,130);
      analogWrite(lm1, 0);
      analogWrite(lm2, 80);
      analogWrite(rm2, 0);
      
      time = millis();
      continue;
    }
   
}
  }