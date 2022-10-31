# STEREO CAMERA ACTUATOR
 This arduino code designed for controlling the angle of 4 servo  motors of a stereo camera system via serial port (UART).
 Each camera can be rotated  0-180 degree in horizontal and vertical direction. Each camera is controlled with two servo motors (one for horizontal movement and another for vertical movement). In this stereo camera system, the actuator controller will be an arduino uno, and the command will be given by a host system/embedded system.  
  
## Arduino signal pin details.  
 * LEFT CAMERA X servo signal pin 3 
 * LEFT CAMERA Y servo signal pin 5
 * RIGHT CAMERA X servo signal pin 6 
 * RIGHT CAMERA Y servo signal pin 9
 
 
 ## The command to control the servos/camera angle
  * The command for controlling the servo angle is recieved via the serial port  (UART). And the data should be in the following string format. 
       *#x1,y1,x2,y2,speed**
    
 *   '#'  - start character of a data frame
 *   x1 - angle for left cam x servo (range =0-180)
 *   y1 - angle for left cam y servo (range =0-180)
 *   x2 - angle for right cam x servo (range =0-180)
 *   y2 - angle for right cam y servo (range =0-180)
 *   speed - The speed in which servo need to reach the final position (range: 100 -- 1000-) (this feature is not active now)
            Instead the servo move very fast
 *   '*' - end character        
    

