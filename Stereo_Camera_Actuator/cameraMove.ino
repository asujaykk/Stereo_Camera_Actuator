
void moveCamera(int posStart[],int posEnd[]){
    /*
     * The following int values are used to identify the direction in which servo need to be rotated.
     */
    int x1,y1,x2,y2;
    x1=posStart[0]-posEnd[0];
    y1=posStart[1]-posEnd[1];
    x2=posStart[2]-posEnd[2];
    y2=posStart[3]-posEnd[3];
    //Serial.println(String(x1)+" "+String(y1)+" "+String(x2)+" "+String(y2));
    
    /*
     * spd variable is calculated based on the average of 4 angle displacenment required.
     * spd= (total delay requested)/ ((average angle displacement)/4)
     * if the calculated value of spd is less than zero the it is set to 1
     */
    int del=posEnd[4];
    //Serial.println(del);
    int spd;
    if (x1 ==0 && y1==0 && x2==0 && y2==0){
      spd=1;    
    }
    else{
      spd=del/((abs(x1)+abs(y1)+abs(x2)+abs(y2))/4);
      if (spd<0){
        spd=1;   
      }
      //spd= spd*10;
    }
    
    /*
     * The eyepos array will be passed to servo_write() method
     * eyepos will be updated with 1 degree incriment/decriment until it matches with posEnd array value
     */
    
    int eyepos[4];
    arrayCopy(posStart,eyepos);
    
    while(true){
      if((x1<0) && eyepos[0]!=posEnd[0]){
        eyepos[0]+=1;
      }
      else if ((x1>0)  && eyepos[0]!=posEnd[0]){
        eyepos[0]-=1;
      }

      if((y1<0) && eyepos[1]!=posEnd[1]){
        eyepos[1]+=1;
      }
      else if ((y1>0) && eyepos[1]!=posEnd[1]){
        eyepos[1]-=1;
      }

      if((x2<0) && eyepos[2]!=posEnd[2]){
        eyepos[2]+=1;
      }
      else if ((x2>0) && eyepos[2]!=posEnd[2]){
        eyepos[2]-=1;
      }

      if((y2<0) && eyepos[3]!=posEnd[3]){
        eyepos[3]+=1;
      }
      else if ((y2>0) && eyepos[3]!=posEnd[3]){
        eyepos[3]-=1;
      }

      /*    
       *     servoWrite() method call
       */
      servoWrite(eyepos,spd);

      /*
       * break the loop once all servo reaches the requested position
       */
      if (eyepos[0]==posEnd[0] && eyepos[1]==posEnd[1] && eyepos[2]==posEnd[2] && eyepos[3]==posEnd[3]){
        //ser_send_data("here");
        break;
      }
    }  
     
}

/*
 * The following method will drive 4 servo to the angle specified in 'eyepos[]' array
 * The 'spd' value determine the delay between each servo update
 */

void servoWrite(int eyepos[],int spd){
    //Serial.println("A="+String(spd)+" "+String(eyepos[0])+" "+String(eyepos[1])+" "+String(eyepos[2])+" "+String(eyepos[3]));
    myservof1x.write(eyepos[0]);              
    myservof2x.write(eyepos[2]);
    myservof1y.write(eyepos[1]);
    myservof2y.write(eyepos[3]);
    delay(spd);
}
