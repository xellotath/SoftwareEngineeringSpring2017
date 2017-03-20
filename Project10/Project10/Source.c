#include <stdio.h>
#include <stdlib.h>
#include "commands.h"
#include "map.h"
#include "randomization.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma disable(warning: 4996)

int algo(int current_try, int(*room_center)[25]);



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
				map[current_try + 1][i][j] = map[0][i][j];
			}
		}



		if (algo(current_try, room_center)) {

			break;
		}


	}

	for (;;) {
		getchar();
		system("cls");

		for (i = 0;i < 25;i++) {
			printf("%s\n", map[current_try][i]);
		}

		printf("\n");


		input(current_try);



	}

	return 0;
}


int algo(int current_try, int(*room_center)[25]) {

	if (current_try < 5) {
		return randomize(current_try, room_center);
	}
	else {
		return randomize_2(current_try, room_center);
	}


}