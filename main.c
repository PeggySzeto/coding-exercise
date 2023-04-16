#include <stdio.h>
#include <string.h>
#include <unistd.h>           //assume Linux platform to support sleep() function.                   

#define MONITOR_SECOND   			2    	//in term of seconds. The duration of monitoring the status. if this rate set fast, the response is fast, but CPU need to more loading => increase the current => not good for battery operation.
#define SECONDS_PER_DAY       24*60*60


void MainLoop()
{
		char CurrentState;
		unsigned int Position;
		unsigned int DurationTime;
		unsigned arrLength;
		unsigned int Hour;
		unsigned int min;
		char Time[4];
		
		CurrentState = 0xff;  		//initial the current state => not a valid state => used for print at the startup; 
		Position =  0;            //If the system can get current time, the postion can modify by the current time by using the lenght of string.	
		DurationTime =0;          
		while (1)    
    {
   	  	char *Sch[] = GetScheduleStdinFunction(stdin);   //output function=> schular my test case: "123456789012345678901234567890123456789012345678";
  		  arrLength = strlen(*Sch);												
  		  if (arrLength != 0)
  		  {	
  		  	  if (DurationTime >= SECONDS_PER_DAY/arrLength)   //Check duration time reach? to check the next state.   
  		  	  {
  		  	  	  DurationTime = 0;
  		  	  	  if (Position >= arrLength)
  		  	  	  {
  		  	  	  	 Position = 0;
  		  	  	  }	
  		  	  	  else
  		  	  	  {
  		  	  	  	 Position++;
  		  	  	  }			
  		  	  }		  	  
  		  	  if (CurrentState != (char) *(Sch[0]+Position))  //check state change?
  		  	  {
  		  	  	 CurrentState = (char) *(Sch[0]+Position);    //the state is changed
  		  	  	 switch(CurrentState)
  		  	  	 {
  		  	  	 		case '1':
  		  	  	 		case '0':
  		  	  	 					Hour = ((Position *(SECONDS_PER_DAY/arrLength))/3600);       //get the time!
  		  	  	 		  		min =  (((Position *(SECONDS_PER_DAY/arrLength))%3600)/60);
  	           					if (Hour < 10)
  	           					{
  	           	  					Time[0] = '0';
  	           					}		
  	           					else
  	           					{
  	           	  					Time[0] = (Hour/10) + '0';
  	           					}		
  	           					Time[1] = (Hour%10) + '0';
  	                		
  	           					if (min < 10)
  	           					{
  	           	  					Time[2] = '0';
  	           					}		
  	           					else
  	           					{
  	           	  					Time[2] = (min/10) + '0';
  	           					}		
  	           					Time[3] = (min%10) + '0';
  	           					
  	           					if (CurrentState == '1')
  	           					{
  	           						  printf("%c%c:%c%c: %s \n",Time[0],Time[1],Time[2],Time[3], "On");   
  	           						 
  	           					}
  	           					else
  	           					{
  	           							printf("%c%c:%c%c: %s \n",Time[0],Time[1],Time[2],Time[3], "Off");   
  	           					}				  	           						
  	           		break; 	           
  	           }
  		  	  }	
   	  	}
   	  	sleep(MONITOR_SECOND);       	  //function for wait 2 second, the users to wait for a current thread for a specific time. Other operations of the CPU will function properly but the sleep() function will sleep the present executable for the specified time by the thread.
        DurationTime += MONITOR_SECOND;
    }
}
