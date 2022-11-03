# STEREO CAMERA ACTUATOR.
 This is an arduino project for controlling the angle of 4 servo  motors of a stereo camera system via serial port (UART) fom a host system.
 Each camera can be rotated from '0' to '180' degree in horizontal and vertical direction. Each camera is controlled with two servo motors (one for horizontal movement and another for vertical movement). Here the controller will be an arduino uno (atmega328p), and the command will be given by a host system/embedded system. For basic projects, this system can be controlled from a laptop with serial connection over usb cae but can also be controlled wirelessly by replacing usb serial connection with a bluetooth module  or wifi esp8266 module. Since we are using simple serial communication, the system can be controlled from android  devices or from any embedded system.
   
   
## Camera pan tilt holder.
The following picture shows the pan tilt camera holder with servos.In which X servo motor rotate the camera platform in horizontal plane (pan movement) and Y servo motor rotate the camera platform in vertical plane (tilt movement).
![Screenshot 2022-11-01 13:06:35](https://user-images.githubusercontent.com/78997596/199183581-3ccb0dbc-64c6-497f-9fea-ee359962270f.png )


## Connection diagram.
The following wiring diagram shows the servo connections to arduino board. Here we are not providing external supply for the servo motors since arduino board can supply enough current to these 4 motors at a time. (if you want to use a high current servo, then please provide seperate power supply for servo motors and arduino board)

![connection](https://user-images.githubusercontent.com/78997596/199190045-70069033-65ad-4977-a04f-8580e5a735d3.png)


## Arduino signal pin details.  
 * LEFT CAMERA X servo signal pin 3 
 * LEFT CAMERA Y servo signal pin 5
 * RIGHT CAMERA X servo signal pin 6 
 * RIGHT CAMERA Y servo signal pin 9
 
 
 ## Flashing the code to arduinio.
 * Ensure that all servos are connected to arduino board  
 * Connect arduino to the laptop/PC using a usb cable.
 * Clone this repository to your PC, with below command  
  
         git clone https://github.com/asujaykk/Stereo_Camera_Actuator.git  
 
 * Open this code in arduino IDE.
 * Compile and upload the code in to your arduino board.
 * After sussefull upload you can see, the servos start rotating...:)
 
 
 ## System initialization and command format.
  * The system will take few seconds to initialize after power up.
  * After successfull initialization, the system send a message "SCA ready" to the host machine through UART.
  * This 'ready' message can be used by host system program to identify the status of SCA module.
  * If this message is not recieved, then it is clear that there is some issue with your SCA module!
  * User can start sending commands to the system after successfull initialization.
  * The command for controlling the servo angle is recieved via the serial port  (UART). And the data frame should be in the following string format.
  
       *#x1,y1,x2,y2,speed**
    
 *   '#'  - start character of a data frame
 *   x1 - angle for left cam x servo (range =0-180)
 *   y1 - angle for left cam y servo (range =0-180)
 *   x2 - angle for right cam x servo (range =0-180)
 *   y2 - angle for right cam y servo (range =0-180)
 *   speed - The speed in which servo need to reach the final position (range: 100 -- 1000-) (this feature is not active now)
            Instead the servo rotate with full speed.
 *   '*' - end character    


## Controlling the system from host pc:
 * Connect arduino to the laptop/PC using a usb cable.
 * wait for the system to initize.
    1. If the system get initialized, then 4 servos will rotate from 0-180 degree and return back to 90 degree angle.  
    2. This initialization is performed to ensure proper working of all servo motors.  
 * Launch any serial terminal application to communicate over serial port (you can use arduino serial terminal itself).  
 * From the application, select the device port and baud rate as 9600.
 * Now you can start sending the command over the serial port with the following format.
    
    *#x1,y1,x2,y2,speed**  
    
   Once you send the command to SCA module, then hopefully two camera platforms should rotate to the requested angle :)



   
