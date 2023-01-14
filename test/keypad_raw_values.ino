//Variable for keypad input
int keyIn = 0;
//Array to store keypad raw values
int keyVals [16] = {
  1, 2, 3, 10,
  4, 5, 6, 11,
  7, 8, 9, 12,
  14, 0, 15, 13
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
  //Print the raw value for each key
  Serial.println(keyIn);
  // It's important to save this values, we will use them to determine the key pressed
  // You can store them in the keyVals array(the value for 1 goes in 1,the value for 2 goes in 2,etc...)
  // 10 is A, 11 is B, 12 is C, 13 is D, 14 is * and 15 is #
  // Also the order matches the keypad, so there should be no confusion
  delay(100);
}
