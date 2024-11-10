//6 Sensors code
#define isBlue 1
#define isWhite 0
int f_s = 2; //D2
int c_s = 3; //D3
int r_s = 18; //D18          Interrupts
int rr_s = 19; //D19
int l_s = 20; //D20
int ll_s = 21; //D21



int lm1 = 4; //pwm
int lm2 = 6;
int rm1 = 5;  //pwm
int rm2 = 7;


void setup() {
  pinMode(f_s, INPUT);
  pinMode(c_s, INPUT);
  pinMode(r_s, INPUT);
  pinMode(rr_s, INPUT);
  pinMode(l_s, INPUT);
  pinMode(ll_s, INPUT);
 

  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);

  Serial.begin(9600);   

} 

void loop() {
  while(1) {
   unsigned long time = millis();
    int fs = digitalRead(f_s);  // read the input pin


    int cs = digitalRead(c_s);  // read the input pin
    

    int rs = digitalRead(r_s);  // read the input pin
   

    int rrs = digitalRead(rr_s);  // read the input pin
   

    int ls = digitalRead(l_s);  // read the input pin
    

    int lls = digitalRead(ll_s); // read the input pin


    if((fs == isBlue) && (cs == isBlue) && (rs == isBlue) && (rrs == isBlue) && (ls == isBlue) && (lls == isBlue)) {  // No Movement
        if((millis() - time) > 1000){
        analogWrite(lm2, 0);
        analogWrite(rm2, 0);
        analogWrite(lm1, 0);
        analogWrite(rm1, 0);
        }
        
    }

    if(fs == isWhite){          // Move forward with full speed
      analogWrite(rm1, 250);
      analogWrite(lm1, 250);
      time = millis();
      continue;
    }
    else {

      analogWrite(rm1, 200);    //Slow Down
      analogWrite(lm1, 200);    //The Robot
      
      if(cs == isWhite && (rs == isBlue) && (rrs == isBlue) && (ls == isBlue) && (lls == isBlue)) {   // Move with slow speed
      analogWrite(rm1, 200);
      analogWrite(lm1, 200);
      time = millis();
      continue;
      }

      if(((rs == isWhite) || (rrs == isWhite)) && (ls == isBlue) && (lls == isBlue) && ((cs == isWhite) || (cs == isBlue))) {   //Move right
      analogWrite(rm1,0);
      analogWrite(lm1, 200);
      analogWrite(lm2, 0);
      analogWrite(rm2, 100);
      time = millis();
      continue;
      }

      if(((ls == isWhite) || (lls == isWhite)) && (rs == isBlue) && (rrs == isBlue) && ((cs == isWhite) || (cs == isBlue))) {   //Move left
      analogWrite(rm1, 200);
      analogWrite(lm1, 0);
      analogWrite(lm2, 100);
      analogWrite(rm2, 0);
      time = millis();
      continue;

     
      }

      if((rs == isWhite) && (rrs == isWhite) && (ls == isWhite) && (lls == isWhite) && ((cs == isWhite) || (cs == isBlue))) {  //choose left from in circle or kite
      analogWrite(rm1, 200);
      analogWrite(lm1, 0);
      analogWrite(lm2, 100);
      analogWrite(rm2, 0);
      time = millis();
      continue;
      }

      if(((rs == isWhite) || (rrs == isWhite)) && ((ls == isWhite) || (lls == isWhite)) && ((cs == isWhite) || (cs == isBlue))) {  //choose left from in circle or kite
      analogWrite(rm1, 200);  
      analogWrite(lm1, 0);
      analogWrite(lm2, 100);
      analogWrite(rm2, 0);
      time = millis();
      continue;
      }

      if((rs == isWhite) && (rrs == isWhite) && (ls == isBlue) && (lls == isBlue) && (cs == isBlue) && ((cs == isWhite) || (cs == isBlue))) {  //90 Degree on right side
      analogWrite(rm1,0);
      analogWrite(lm1, 200);
      analogWrite(lm2, 0);
      analogWrite(rm2, 100);
      time = millis();
      continue;
    }

     if((ls == isWhite) && (lls == isWhite) && (rs == isBlue) && (rrs == isBlue) && ((cs == isWhite) || (cs == isBlue))) {  //90 Degree on left side
      analogWrite(rm1, 200);
      analogWrite(lm1, 0);
      analogWrite(lm2, 100);
      analogWrite(rm2, 0);
      time = millis();
      continue;
    }

    }
  }
}