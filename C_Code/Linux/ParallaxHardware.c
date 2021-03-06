/**
 * @file     ParallaxHardware.c
 * @author   Blaze Sanders (@ROBO_BEV)TM
 * @email    blaze@robobev.com
 * @updated  07 APRIL 2018
 *
 * @version 0.1
 * @brief Manage a two way connection between Linux distro and Parallax hardware
 *
 * @section DESCRIPTION
 *
 * Compiled driver ABOVE code using "g++ DRIVER_NAME.c ParallaxHardware.c -std=c++11 -o APP_NAME"
 */

#include "ParallaxHardware.h"
#include <unistd.h>  //Standard constant and types like usleep(), close(), and pause()

void InitializeParallaxHardware(){
   serialPortNumber = 0;

   parallaxPartNumber = UNSUPPORTED_PARALLAX_PART_NUMBER;
   int parallaxParts[] = new int[DEFAULT_NUM_OF_PARALLAX_PARTS];

   for (int i = 0; i < DEFAULT_NUM_OF_PARALLAX_PARTS; i++){
     parallaxParts[i] = UNSUPPORTED_PARALLAX_PART_NUMBER;
   }//END FOR LOOP

   parallaxParts[0] = RFID_TX_RX_PN28140;
   parallaxParts[1] = ULTRASONIC_SENSOR_PN28015;
   parallaxParts[2] = ULTRASONIC_SENSOR_PN28015;
   parallaxParts[3] = ULTRASONIC_SENSOR_PN28015;

   operatingSystem = BARISTO.WINDOWS_10_PRO_V1709;

   for(int i = 0; i < DEFAULT_NUM_OF_PARALLAX_PARTS; i++){
     parallaxPartNumber = parallaxParts[i];
     ParallaxHardware(serialPortNumber++, parallaxPartNumber, operatingSystem);
   }//END FOR LOOP
}//END InitializeParallaxHardware()


void InitializeParallaxHardware(int portNum, int pPartNum, double opSys){
  serialPortNumber = portNum;
  parallaxPartNumber = pPartNum;
  operatingSystem = opSys;

  //TO-DO: if(Baristo.DEBUG_STATEMENTS_ON) printf("The port number you selected it not available, using port number 1.");
  //TO-DO: serialPortNumber = 0;

}//END THREE PARAMETER ParallaxHardware(INT, INT, DOUBLE) CONSTRUCTOR

public int CreateFullDuplexSerialConnection(int portNum){
  //USB is a serial communication path
  //TO-DO: return Baristo.ERROR_CODE_NO_SERIAL_CONNECTION_MADE;

  return BARISTO.OK; //No errors connection made
}// END MakeSerialConnection() FUNCTION

int IntializeRFID(int bootMode, double verNum, int parrallaxPartNumber){

  return BARISTO.OK; //Intialization OK
}


int IntializeUltrasonicSensors(int bootMode, double verNum, int parrallaxPartNumber, int numOfSensors){

  BootUpChecks(bootMode, verNum);


  switch(parrallaxPartNumber){
    case 28015:

      break;
    default;
      if(Baristo.DEBUG_STATEMENTS_ON) printf("You attempted to use an unsupported Parallax ultrasonic sensor.");
      return UNSUPPORTED_PARALLAX_PART_NUMBER;
  }//END SWTICH STATEMENT

  return BARISTO.OK; //No errors connection made
}//END IntializeUltrasonicSensor FUNCTION


int ScanForRFIDTag(){
  String tag = "0xFFFFFFFF";
  //TO-DO: tag = ReadTag();
  //TO-DO: SearchTagDatabase(tag);
  //TO-DO: return BARISTO.ERROR_CODE_???

  return BARISTO.OK; //No errors connection made
}//END ScanRFID() FUNCTION

int BootUpChecks(int bootMode, double verNum){

  if (bootMode == BARISTO->PRODUCTION) BARISTO->DEBUG_STATEMENTS_ON = false;
  else BARSITO.DEBUG_STATEMENTS_ON = true;
    if (verNum > Baristo.CURRENT_KIOSK_HW_VERSION){
      if(Baristo.DEBUG_STATEMENTS_ON){
        printf("You attempted to run non-public and unsupported software.\n");
        printf("50 cent is coming for you :)");
      }
    }
    else if (verNum < Baristo.LOWEST_SUPPORTED_KIOSK_HW_VERSION){
      if(DEBUG_STATEMENTS_ON){
        printf("You attempted to run old unsupported software.");
        printf("Please download newest open source code from https:\/\/github.com/ROBO-BEV/BARISTO");
      }
      return ERROR_CODE_OLD_VERSION_NUMBER;
  }
}//END BootUpChecks() FUNCTION


int[] GetDistance(int numOfSensors, int[] signalPins char units){

  int distance = new int[MAX_NUM_OF_PING_SENSORS];
  switch(units){
    case 'M':		//Fall through capital M so that both cases are catch
    case 'm':
      for (int i = 0; i < numOfSensors; i++){
        distance[i] = ping_cm(signalPins[i]);        // Get cm distance from PINGs connection to defined GPIO pins
      }//END FOR LOOP
      if(DEBUG_STATEMENTS_ON) printf("Distance measured by PING sensor#%d = %d centimeters \n", i, distance);
      break;
    case 'I':		//Fall through capital M so that both cases are catch
    case 'i':
      //TODO COPY CODE ABOVE FOR INCHES
      break;
    default:
      assert(false); print("GetDistance() function was passed an invalid UNITS parameter");

  }//END SWITCH

}//END  GetDistance

