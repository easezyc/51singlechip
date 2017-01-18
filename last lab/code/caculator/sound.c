#include<head.h>
sbit speaker=P1^7;
void Task3_Sound(void) _task_ TASK3	 //´íÎóÌáÊ¾Òô
{
	while(1){
		if(sound==1)speaker=~speaker;			
	}
}