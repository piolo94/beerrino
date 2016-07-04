#define IN_1 3                      //initialize pin on motorshield
#define INH_1 12
#define DCMAX 30             //define max val of dutycycle
byte echoPin=13;                 // "echo" pin of ultrasound sensor
byte trigPin=2;                    //"trigger" pin of ultrasound sensor
unsigned int distance;       // distance from obstacles
int dc;                                   //current dutycycle value
int interrupt=A2;              // interrupt pin
int flag;                               //flag readed on interrupt pin
int dir1=6;                        //pin for direction of the first stepper motor
int dir2=7;                       //pin for direction of the second stepper motor
int step1=8;                     //pin for single step of the first stepper motor
int step2=9;                     //pin for single step of the second stepper motor
void setup(){
  pinMode(trigPin, OUTPUT);           
pinMode(echoPin, INPUT);
pinMode(IN_1, OUTPUT);
pinMode(INH_1, OUTPUT);
pinMode(flag, INPUT);
digitalWrite(INH_1,HIGH);              //hinibite brushmotor
pinMode(dir1,OUTPUT);
pinMode(dir2, OUTPUT);
pinMode(step1, OUTPUT);
pinMode(step2, OUTPUT);
digitalWrite(dir1, LOW);
digitalWrite(dir2, LOW);
digitalWrite(step1, LOW);
digitalWrite(step2, LOW);
}

void loop(){
    flag=analogRead(interrupt);                                   
    if(flag>100){                          
        byte i; 
        delay(1000);                      
        distance=distanza();   //compute distance between robot and obstacle
        if(distance>10){              // if distance > 10cm
            for(i = 0; i<DCMAX; i++){                    //DCMAX = max value of duty cycle
                dc= map(i,0,100,0,255);               //map the value of duty cycle in percentual point
                analogWrite(IN_1,dc);             //give a signal with the current duty cycle value
            }
            distance=distanza();                       
            delay(100);                                
            while(distance>10){                          
                distance=distanza();                     
                delay(100);
            }
            delay(500);                           
            dc=0;                        //duty-cycle @ zero
            digitalWrite(IN_1,dc);           //stop motor
            delay(1000);                   
            stappa();                //function that opens the can
        }
    }
}

int distanza(){                //compute distance between obstacles and robot
    long duration,r;               

    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
    duration = pulseIn(echoPin, HIGH); 
    r=0.034*duration/2; // calcola la distanza

    return r;
}

void stappa(){           
int i;

digitalWrite(dir1, LOW);
digitalWrite(dir2, LOW);

for(i=0; i<1000; i++){ // the first stepper motor open the can
digitalWrite(step1, HIGH);
delay(1);
digitalWrite(step1, LOW);
delay(1);

}

delay(1000);

digitalWrite(dir1, HIGH); //change rotation sense

for(i=0; i<1000; i++){           //the first stepper motor goes back
digitalWrite(step1, HIGH);
delay(1);
digitalWrite(step1, LOW);
delay(1);
}

for(i=0; i<1000; i++){         // the second stepper motor makes turn the robotic arm
digitalWrite(step2, HIGH);
delay(1);
digitalWrite(step2, LOW);
delay(1);
}

delay(3000);
digitalWrite(dir2,HIGH); // changes rotation sense

for(i=0; i<1000; i++){
digitalWrite(step2, HIGH); //the second stepper motor goes back
delay(1);
digitalWrite(step2, LOW);
delay(1);
}
}

