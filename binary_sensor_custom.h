#include "esphome.h"
#include "esphome.h"

class MyCustomBinarySensor : public PollingComponent, public BinarySensor {
    public:
    // constructor
    MyCustomBinarySensor() : PollingComponent(16) {}

    BinarySensor *arm = new BinarySensor();
    BinarySensor *disarm = new BinarySensor();

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
    int cooldown = 0;
    char last_key = '#';
    void setup() override {
    // This will be called by App.setup()
    }
    void update() override {
    // This will be called every "update_interval" milliseconds.
    keyIn =  analogRead(A0);//Read in keypad input
    for (int i=0; i<=15; i++)//Run through the array of button values
    {
        if (keyIn >= keyVals[i]-range && keyIn <= keyVals[i]+range)//If the measured value is in the range of one key
        {
            if(last_key != keys[i]){
                char myKey = keys[i];
                if (keys[i] == 'A'){
                    delay(50);
                    arm->publish_state(true);
                    delay(300);
                    arm->publish_state(false);
                    last_key = keys[i];
                }else if (keys[i] == 'B'){
                }else if (keys[i] == 'C'){
                }else if (keys[i] == 'D'){
                    delay(50);
                    disarm->publish_state(true);
                    delay(300);
                    disarm->publish_state(false);
                    last_key = keys[i];
                }
            }
        }
        if(cooldown >= 200){
            last_key='\0';
            cooldown=0;
        }
        cooldown++;
    }
    }
};