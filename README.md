# STEREO CAMERA ACTUATOR
 * This software designed for controlling the angle of two cameras to achive stereo vision
 * Each camera can be rotated through 180 degree in horizontal and vertical direction
 * Each camera is controlled with two servo motors (one for horizontal movement and another for vertical movement) 
 * 
 * LEFT CAMERA X servo signal pin 3 
 * LEFT CAMERA Y servo signal pin 5
 * RIGHT CAMERA X servo signal pin 6 
 * RIGHT CAMERA Y servo signal pin 9
 *
 * The command for controlling the servo angle is recieved via the serial port  (UART)
 * The command format is as follows
 *   
 *   #x1,y1,x2,y2,speed*
 *   
 *   #  - start character of a data frame
 *   x1 - angle for left cam x servo (range =0-180)
 *   y1 - angle for left cam y servo (range =0-180)
 *   x2 - angle for right cam x servo (range =0-180)
 *   y2 - angle for right cam y servo (range =0-180)
 *   speed - The speed in which servo need to reach the final position (range: 100 -- 1000-) (this feature is not active now)
 *           Instead the servo move very fast
 *           
 *   
 *  ############################################################################### 
