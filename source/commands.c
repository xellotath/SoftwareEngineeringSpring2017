#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "randomization.h"

void test_move(int current_try, int player_location[], int direction, int *v, int(*visited)[25]) {//direction is an int, 1 means up, 2 is right, 3 is down, 4 is left

	int i;
	int was = 0;
	int p = *v;
	int g;

	if (direction == 1) {
		if (map[current_try][player_location[0] - 2][player_location[1]] == '|') {
			player_location[0] -= 5;
			for (i = 0;i <= p+1;i++) {
				if (visited[0][i] == player_location[0] && visited[1][i] == player_location[1]) {
					was = 1;
				}
			}
			if (was == 0) {
				g = p;
				visited[0][g + 1] = player_location[0];
				visited[1][g + 1] = player_location[1];
				p++;
				*v = p;
			}

		}
	}
	else if (direction == 3) {
		if (map[current_try][player_location[0] + 2][player_location[1]] == '|') {
			player_location[0] += 5;
			for (i = 0;i <= p+1;i++) {
				if (visited[0][i] == player_location[0] && visited[1][i] == player_location[1]) {
					was = 1;
				}
			}
			if (was == 0) {
				g = p;
				visited[0][g + 1] = player_location[0];
				visited[1][g + 1] = player_location[1];
				p++;
				*v = p;
			}
		}
	}
	else if (direction == 2) {
		if (map[current_try][player_location[0]][player_location[1] + 3] == '=') {
			player_location[1] += 6;
			for (i = 0;i <= p+1;i++) {
				if (visited[0][i] == player_location[0] && visited[1][i] == player_location[1]) {
					was = 1;
				}
			}
			if (was == 0) {
				g = p;
				visited[0][g + 1] = player_location[0];
				visited[1][g + 1] = player_location[1];
				p++;
				*v = p;
			}
		}
	}
	else if (direction == 4) {
		if (map[current_try][player_location[0]][player_location[1] - 3] == '=') {
			player_location[1] -= 6;
			for (i = 0;i <= p+1;i++) {
				if (visited[0][i] == player_location[0] && visited[1][i] == player_location[1]) {
					was = 1;
				}
			}
			if (was == 0) {
				g = p;
				visited[0][g + 1] = player_location[0];
				visited[1][g + 1] = player_location[1];
				p++;
				*v = p;
			}
		}
	}

}

void move(int current_try, int player_location[], int direction) {





}