int sw1 = 4; // declaring pin 4 as switch 1
int sw2 = 6; // declaring pin 6 as switch 2
int sigA = 1;// declaring pin 1 as signal A or LED 1
int sigB = 3;// declaring pin 3 as signal B or LED 2
int rsw1 = 0;// declaring a variable to read from switch 1 initially set as LOW
int rsw2 = 0;// declaring a variable to read from switch 2 initially set as LOW
int a = 1100;// parameter 'a' calculated as first letter*100 = 11*100 = 1100
int r = 1600;// parameter used in mode '2' where we reverse the signal, hence highest value is a+(c-1)*b = 1600
int b = 100;// parameter 'b' calculated as second letter*100 = 1*100 = 100
int c = 11; // parameter 'c' calculated as third letter+4 = 7+4=11
int d = 3500;// parameter 'd' calculated as fourth letter*500 = 7*500 = 3500
// mode is calculated as rem(fifth letter/4) + 1 = rem(1/4) + 1 = 2. Hence we use mode 2

void setup() {
  // put your setup code here, to run once:
  pinMode(sw1, INPUT); // setting sw1 pin(switch 1) as INPUT
  pinMode(sw2, INPUT); // setting sw2 pin(switch 2) as INPUT
  pinMode(sigA, OUTPUT);// setting sigA pin(LED 1/signal A) as OUTPUT
  pinMode(sigB, OUTPUT);// setting sigB pin(LED 2/signal B) as OUTPUT

}

void loop() {
  // put your main code here, to run repeatedly:
  rsw1 = digitalRead(sw1); // reading from sw1 and storing it in rsw1
  rsw2 = digitalRead(sw2); // reading from sw2 and storing it in rsw2
  
  if(rsw1 == HIGH)         // using if else to 
  {
    digitalWrite(sigA, LOW);
    digitalWrite(sigB, LOW);

  }

  else{

    if(rsw2 == LOW)
    {
      digitalWrite(sigB, HIGH);
      delay(50);
      digitalWrite(sigB, LOW);

      for(int i =0;i<c;i++)
      {
        digitalWrite(sigA, HIGH);
        delay(a);
        digitalWrite(sigA, LOW);
        delay(b);
        a = a+50;
      }
      digitalWrite(sigA, LOW);
      delay(d);
    }

    else
    {
      digitalWrite(sigB, HIGH);
      delay(50);
      digitalWrite(sigB, LOW);

      for(int i =0; i<c;i++){

        digitalWrite(sigA, HIGH);
        delay(r);
        digitalWrite(sigA, LOW);
        delay(b);
        r = r-50;
      }

      digitalWrite(sigA, LOW);
      delay(d);


    }

  }

}
