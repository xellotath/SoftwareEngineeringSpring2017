#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int i=0;
	int j=0;
	int h;
	//int room_center[2][6] = {{1,1,4,4,7,7},{3,11,3,11,3,11}}; //first set of integers are rows, second set of integers are columns
	int room_center[2][18];
	int m=0;
	int n=0;

	
	for (m=0;m<20;m+=5){
		for (n=0;n<20;n+=5){
				room_center[0][i] = 2 + m;
				room_center[1][i] = 2 + n;
				i++;
		}
	}


	for (i=0;i<16;i++){
		printf("%d %d\n",room_center[0][i], room_center[1][i]);
	}


		return 0;
}
