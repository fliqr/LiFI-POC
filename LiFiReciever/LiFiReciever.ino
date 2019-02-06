int solarInput;
int intervalCounter;
String inputString = "";
int inputStringIndex = 0;
int cutoffValue = 500;
int startBit = 0;
int codeIsDone = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0, INPUT);
}

void loop() {
    //sequence is starting. this is the time of the startBit
    while(analogRead(A0) < cutoffValue){
        intervalCounter++;
    }
    startBit = intervalCounter;
    //Serial.print(startBit);
    //Serial.println("************");

    
    //general code for the rest of the signal
    while(intervalCounter <= startBit && startBit > 40){
        intervalCounter = 0;
        //high signal
        
        while(analogRead(A0) > cutoffValue){
            intervalCounter++;
        }
        //Serial.print("On:");
        //Serial.println(intervalCounter);
        if(intervalCounter > startBit){
            codeIsDone = true;
            break;
        }
        if(intervalCounter > 15){
            Serial.print("1");
            inputString.concat("1");
        } else {
          
            Serial.print("0");
            inputString.concat("0");
        }
        
        intervalCounter = 0;

        while(analogRead(A0) <= cutoffValue){
            intervalCounter++;
        }
        //Serial.print("Off:");
        //Serial.println(intervalCounter);
    }
    if(codeIsDone || intervalCounter > startBit){
        intervalCounter = 0;
        //Serial.println("Signal over");
        //Serial.println(inputString);
        Serial.println();
        inputString = "";
        //signal has ended
    }
        
    
    
}

