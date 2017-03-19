#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int i;
	int j=0;

	char map[9][16]={{"------- -------"},
					 {"|     | |     |"},
					 {"------- -------"},
					 {"------- -------"},
					 {"|     | |     |"},
					 {"------- -------"},
					 {"------- -------"},
					 {"|     | |     |"},
					 {"------- -------"}};


	for(i=0;i<=8;i++){
	//	for(j=0;j<=15;j++){
		
			printf("%s",&map[i][j]);
		
	//	}
		printf("\n");
	}


	int room_center[2][6] = {{1,1,4,4,7,7},{3,11,3,11,3,11}}; //first set of integers are rows, second set of integers are columns

	srand(time(NULL));
	int r = rand() % 6;

	map[room_center[0][r]][room_center[1][r]]='@';
	
		for(i=0;i<=8;i++){
	//	for(j=0;j<=15;j++){
		
			printf("%s",&map[i][j]);
		
	//	}
		printf("\n");
	}

		return 0;
}
