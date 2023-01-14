//Variable for keypad input
int keyIn = 0;
//Tolerance above or below the numerical value
int range = 1;
//Array to store keypad raw values
int keyVals [16] = {
  714, 700, 689, 678,
  634, 616, 603, 588,
  569, 544, 525, 505,
  481, 445, 413, 382
  }; 
//Characters corressponding to each key
char keys [16] = {
  '1','2','3','A',
  '4','5','6','B',
  '7','8','9','C',
  '*','0','#','D'
  };
void setup() {
  //Initialize serial
  Serial.begin(115200);
}

void loop() 
{
  //Read the Analog pin, where we connected the voltage divider
  keyIn = analogRead(A0);
  for (int i=0; i<=15; i++)     //Run through the array of button values
  {
    if (keyIn >= keyVals[i]-range && keyIn <= keyVals[i]+range)   //If the measured value is in the range of one key
    {
      Serial.println(keys[i]);
    }
  }
}
