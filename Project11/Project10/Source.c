#include <stdio.h>
#include <stdlib.h>
#include "commands.h"
#include "map.h"
#include "randomization.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma disable(warning: 4996)

int algo(int current_try, int(*room_center)[25]);//algo prototype



int main(void)
{
	int current_try = 1;//this holds the number of tries it has taken for a map to be generated
	int i = 0;//loop variable
	int j = 0;//loop variable


	int room_center[3][25];//declaration of room centers' array

	get_center(room_center);//fill that array


	for (;current_try < 8;current_try++) {
		//this loop copies the original map that has no pathways
		//on the next two higher levels of the 3d array to randomize;
		//saving the original to use as the master map
		//(there is a note for the need for the extra vesion created at randomization.c)

		for (i = 0;i < 25;i++) {
			for (j = 0;j < 30;j++) {
				map[current_try][i][j] = map[0][i][j];
				map[current_try + 1][i][j] = map[0][i][j];
			}
		}

		//it then randomizes the created map

		if (algo(current_try, room_center)) {
			//it only breaks if the map is valid, which is bound to happen at least
			//once when the seconds randomization algorithm is used
			break;
		}


	}

	for (;;) {
		//another endless loop to allow for gameplay
		//this only ends if the player wins.
		//if the player meets enemy reset is called.

		getchar();
		system("cls");//screen is cleared and then map gets reprinted to reflect changes made after a command

		for (i = 0;i < 25;i++) {
			printf("%s\n", map[current_try][i]);
		}

		printf("\n");


		input(current_try);//accepts input from the player and checks it against the defaults
		//an output may or may not be explicitly printed



	}

	return 0;
}


int algo(int current_try, int(*room_center)[25]) {
	//this is the function that switches algorithms. is called indefinitely.
	//however, at least one of the maps created from randomize_2 is bound to be valid
	//therefore current_try will not exceed the capacity of char map.

	//it calls a series of int functions that will ultimately return 1 if the map is valid
	//and 0 for invalid. after 4 tries it switches to randomize_2

	if (current_try < 5) {
		return randomize(current_try, room_center);
	}
	else {
		return randomize_2(current_try, room_center);
	}


}