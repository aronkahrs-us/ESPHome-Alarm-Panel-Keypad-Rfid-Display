#include "esphome.h"

class MyCustomTextSensor : public PollingComponent, public TextSensor {
    public:
    // constructor
    MyCustomTextSensor() : PollingComponent(16) {}
    TextSensor *code = new TextSensor();
    TextSensor *live = new TextSensor();
    //Variable for keypad input
    int keyIn = 0;
    //Array to store keypad numerical values
    int keyVals [16] = {
    714, 700, 689, 678,
    634, 616, 603, 588,
    569, 544, 525, 505,
    481, 445, 413, 382
    };
    //Key characters corressponding to each numerical value
    char keys [16] = {
    '1','2','3','A',
    '4','5','6','B',
    '7','8','9','C',
    '*','0','#','D'
    };
    //Tolerance above or below the numerical value
    int range = 1;
    std::string keysequenz;
    static const unsigned int resetTime = 5;
    int cooldown = 0;
    unsigned int resetCounter = 0;
    bool keyPressed = false;
    char last_key = '#';
    void setup() override {
    // This will be called by App.setup()
    }
    void update() override {
    // This will be called by App.loop()
    keyIn =  analogRead(A0);//Read in keypad input
    for (int i=0; i<=15; i++)//Run through the array of button values
    {
    if (keyIn >= keyVals[i]-range && keyIn <= keyVals[i]+range)//If the measured value is in the range of one key
    {
    if(last_key != keys[i]){
        char myKey = keys[i];
        if(keys[i]=='#'){
            code->publish_state(keysequenz);
            live->publish_state(keysequenz);
            keysequenz.clear();
            resetCounter = 0;
            keyPressed = false; 
        }else if (keys[i] == '*'){
            keysequenz.clear();
            code->publish_state(keysequenz);
            live->publish_state(keysequenz);
            resetCounter = 0;
            keyPressed = false; 
        }else if (keys[i] == 'A'){
            code->publish_state(keysequenz);
            delay(100);
            keysequenz.clear();
            code->publish_state(keysequenz);
            live->publish_state(keysequenz);
        }else if (keys[i] == 'B'){
            keysequenz.pop_back();
            live->publish_state(keysequenz);
            resetCounter--;
        }else if (keys[i] == 'C'){
        }else if (keys[i] == 'D'){
            code->publish_state(keysequenz);
            delay(100);
            keysequenz.clear();
            code->publish_state(keysequenz);
            live->publish_state(keysequenz);
        }else {
            keysequenz.push_back(myKey);
            live->publish_state(keysequenz);
            keyPressed = true;
        }
        if (keyPressed){
            resetCounter++;
        }
        if (resetCounter >= resetTime){
            keysequenz.clear();
            code->publish_state(keysequenz);
            live->publish_state(keysequenz);
            resetCounter = 0;
            keyPressed = false;
        }    //Set temp equal to the character for that key
        }
    last_key = keys[i];
    }
    }
    if(cooldown >= 400){
        last_key='\0';
        cooldown=0;
    }
    cooldown++;
    }
};