
/*
 * ##################################################
 *            STEREO CAMERA ACTUATOR
 * This software designed for controlling the angle of two cameras to achive stereo vision
 * Each camera can be rotated through 180 degree in horizontal and vertical direction
 * Each camera is controlled with two servo motors (one for horizontal movement and another for vertical movement) 
 * 
 * LEFT CAMERA X servo signal pin 3 
 * LEFT CAMERA Y servo signal pin 5
 * RIGHT CAMERA X servo signal pin 6 
 * RIGHT CAMERA Y servo signal pin 9
 *
 * The command for controlling the servo angle is recieved via the serial port 
 * The command format is as follows
 *   
 *   #x1,y1,x2,y2,speed*
 *   
 *   #  - start character of a data frame
 *   x1 - angle of left cam x servo (range =0-180)
 *   y1 - angle of left cam y servo (range =0-180)
 *   x2 - angle of right cam x servo (range =0-180)
 *   y2 - angle of right cam y servo (range =0-180)
 *   speed - The speed in which servo need to reach the final position (range: 100 -- 1000-) (this feature is not active now)
 *           Instead the servo move very fast
 *           
 *   
 *  ############################################################################### 
 *   
 */



#include <Servo.h>


#define ELEMENTS_PER_DATA 5   /* data elements are : x1,y1,x2,y2,speed 
                               * data format= #x1,y1,x2,y2,speed*
                               * example: #90,90,90,90,1000*
                               */


#define MAX_CHAR_PER_DATA 20  /* maximum charachters required to represent full dataframe is 20 (excluding start and stop characters)
                              /* (x1,y1,x2,y2 need max 3 char each) total 3*4=12
                              /* character required for speed  = 4
                              /* total speration (,) characters= 4
                              /* total= 12+4+4=20
                               */

/* 
 * create 4 servo object for two cameras
 */
Servo myservof1x;   //LEFT CAM x servo
Servo myservof1y;   //LEFT CAM y servo
Servo myservof2x;   //RIGHT CAM x servo
Servo myservof2y;   //RIGHT CAM y servo


void setup() {
  // attaches the servo on pins to the servo objects
  myservof2x.attach(3);  
  myservof2y.attach(5);
  myservof1x.attach(6);
  myservof1y.attach(9);
  Serial.begin(9600);

  //Below code will rotate 4 servo motors from 0-180 degree to confirm they are working fine.
  
  int pos;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservof1x.write(pos);              // tell servo to go to position in variable 'pos'
    myservof2x.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 90 degrees
    myservof1x.write(pos);              // tell servo to go to position in variable 'pos'
    myservof2x.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservof1y.write(pos);              // tell servo to go to position in variable 'pos'
    myservof2y.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 90 degrees
    myservof1y.write(pos);              // tell servo to go to position in variable 'pos'
    myservof2y.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

/*
 * SAMPLE data= #x1,y1,x2,y2,speed*
 * x1,y1,x2,y2 range = 0-180
 * speed range:  100 -- 10000
 * example: #90,90,90,90,1000*
 */

int eyePosEnd[ELEMENTS_PER_DATA]={90,90,90,90,100};  // The array store stop angle for all servos 
int eyePosStrt[ELEMENTS_PER_DATA]={90,90,90,90,100}; // The array store start/current angle for all servos
void loop() {
    String edata;                      //String to store input data frame (excluding start and stop)
    String edataA[ELEMENTS_PER_DATA];  // string array to store splited data frame
    
    //read serial data and store it to 'edata' excluding start and stop characters
    edata=read_data('#','*');    

    // extract each element in the 'edata' and store to 'edataA'
    split_String(edata,edataA,',');   
    
    // update stop angle for all servos (content of 'eyePosEnd') from 'edataA'
    update_eyepos_array(edataA,eyePosEnd);  

    // move camera from current angle to stop angle.
    moveCamera(eyePosStrt,eyePosEnd);    

    // update current angle array 'eyePosEnd' with 'eyePosEnd'.
    arrayCopy(eyePosEnd,eyePosStrt);   
}
