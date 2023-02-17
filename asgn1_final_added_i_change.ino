int sw1 = 1; // declaring pin 4 as switch 1
int sw2 = 2; // declaring pin 6 as switch 2
int sigA = 9;// declaring pin 1 as signal A or LED 1
int sigB = 6;// declaring pin 3 as signal B or LED 2
int rsw1 = 0;// declaring a variable to read from switch 1 initially set as LOW
int rsw2 = 0;// declaring a variable to read from switch 2 initially set as LOW
int a = 1.100;// parameter 'a' calculated as first letter*100 = 11*100 = 1100
int r = 1.600;// parameter used in mode '2' where we reverse the signal, hence highest value is a+(c-1)*50 = 1600
int b = 0.100;// parameter 'b' calculated as second letter*100 = 1*100 = 100
int c = 11; // parameter 'c' calculated as third letter+4 = 7+4=11
int d = 3.500;// parameter 'd' calculated as fourth letter*500 = 7*500 = 3500
// mode is calculated as rem(fifth letter/4) + 1 = rem(1/4) + 1 = 2. Hence we use mode 2
// all the parameters are supposed to be microseconds, but here they work as milliseconds as Arduino IDE takes them in milliseconds

void setup() {
  // put your setup code here, to run once:
  pinMode(sw1, INPUT); // setting sw1 pin(switch 1) as INPUT
  pinMode(sw2, INPUT); // setting sw2 pin(switch 2) as INPUT
  pinMode(sigA, OUTPUT);// setting sigA pin(LED 1/signal A) as OUTPUT
  pinMode(sigB, OUTPUT);// setting sigB pin(LED 2/signal B) as OUTPUT

}

void loop() 
{
  a=1100;
  r =1600;
  rsw2 = digitalRead(sw2);
  if (rsw2 == LOW) // if switch is not pressed, then normal wave form is generated, switch 1 is checked internally
  {

    digitalWrite(sigB, HIGH);
    delay(50);
    digitalWrite(sigB, LOW);// These 3 lines are used to indicate the begin of the cycle by glowing the LED2 for 50 microsec

    for(int i =0;i<c;i++)// To generate 'c' pulses in each block, use for loop. c here is 11
    {

      rsw1 = digitalRead(sw1);
      if (rsw1 == HIGH)// read switch 1 every time, and if it high, turn off the signal i.e., make both the LEDs LOW, until it turns back to LOW
      {
        digitalWrite(sigA, LOW);
        digitalWrite(sigB, LOW);
        i = -1;        // changing 'i' to '-1' again, so that for loop starts again 
      }
      else             // Once switch 1 turns to LOW, generate the normal waveform again
      {
        digitalWrite(sigA, HIGH);
        delay(a);
        digitalWrite(sigA, LOW);
        delay(b);
        a = a+50;
      }
    }
    delay(d); // delay 'd' is given after every cycle
  }

  else       // if switch is pressed, then moded wave form is generated, switch 1 is checked internally
  {
    digitalWrite(sigB, HIGH);
    delay(50);
    digitalWrite(sigB, LOW);

    for(int i =0;i<c;i++) // same as above
    {

      rsw1 = digitalRead(sw1);
      if (rsw1 == HIGH) // same as above
      {
        digitalWrite(sigA, LOW);
        digitalWrite(sigB, LOW);
        i = -1;         // changing 'i' to '-1' again, so that for loop starts again
      }
      else       // Once switch 1 turns to LOW, generate the moded waveform again
      {
        digitalWrite(sigA, HIGH);
        delay(r);
        digitalWrite(sigA, LOW);
        delay(b);
        r = r-50;
      }
    }
    delay(d); // same as above
  }
}