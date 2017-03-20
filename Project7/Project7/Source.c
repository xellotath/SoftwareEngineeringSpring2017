#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "randomization.h"
#include "commands.h"

void algo(int current_try, int(*room_center)[25]);



int main(void)
{
	int current_try = 1;
	int i = 0;
	int j = 0;



	int room_center[3][25];
	get_center(room_center);

	for (;current_try < 8;current_try++) {


		for (i = 0;i < 25;i++) {
			for (j = 0;j < 30;j++) {
				map[current_try][i][j] = map[0][i][j];
			}
		}



		algo(current_try, room_center);













	}


	return 0;
}


void algo(int current_try, int(*room_center)[25]) {

	if (current_try < 5) {
		randomize(current_try, room_center);
	}
	else {
		randomize_2(current_try, room_center);
	}


}