#include "commands.h"


void input(int current_try) {

	int i = 0;
	char user_input[50];
	char *tokens[3] = { NULL, NULL, NULL };
	char *temp;

	gets(user_input);
	//printf("%s\n", user_input);

	temp = strtok(user_input, " ");

	while (temp != NULL && i<3)
	{
		tokens[i++] = temp;
		temp = strtok(NULL, " ");
	}

	if (strcmp(tokens[0],"go") == 0) {
		if (strcmp(tokens[1], "up") == 0) {
			if (tokens[2] != NULL) {
				if (strlen(tokens[2]) == 1) {
					if (atoi(tokens[2]))
					{
						if (atoi(tokens[2]) == 1) {
							printf("Please enter a value between 2-9 for multiple stepls.");
							getchar();
						}
						else {
							for (i = 0;i < atoi(tokens[2]);i++) {
								move(current_try, 1);
							}
						}
					}
					else {
						printf("Please enter a value between 2-9 for multiple stepls.");
						getchar();
					}
				}
				else {
					printf("Please enter a value between 2-9 for multiple stepls.");
					getchar();
				}
			}
			else {
				move(current_try, 1);
			}
		}
		else if (strcmp(tokens[1], "down") == 0) {
			if (tokens[2] != NULL) {
				if (strlen(tokens[2]) == 1) {
					if (atoi(tokens[2]))
					{
						if (atoi(tokens[2]) == 1) {
							printf("Please enter a value between 2-9 for multiple stepls.");
							getchar();
						}
						else {
							for (i = 0;i < atoi(tokens[2]);i++) {
								move(current_try, 3);
							}
						}
					}
					else {
						printf("Please enter a value between 2-9 for multiple stepls.");
						getchar();
					}
				}
				else {
					printf("Please enter a value between 2-9 for multiple stepls.");
					getchar();
				}
			}
			else {
				move(current_try, 3);
			}
		}
		else if (strcmp(tokens[1], "left") == 0) {
			if (tokens[2] != NULL) {
				if (strlen(tokens[2]) == 1) {
					if (atoi(tokens[2]))
					{
						if (atoi(tokens[2]) == 1) {
							printf("Please enter a value between 2-9 for multiple stepls.");
							getchar();
						}
						else {
							for (i = 0;i < atoi(tokens[2]);i++) {
								move(current_try, 4);
							}
						}
					}
					else {
						printf("Please enter a value between 2-9 for multiple stepls.");
						getchar();
					}
				}
				else {
					printf("Please enter a value between 2-9 for multiple stepls.");
					getchar();
				}
			}
			else {
				move(current_try, 4);
			}
		}
		else if (strcmp(tokens[1], "right") == 0) {
			if (tokens[2] != NULL) {
				if (strlen(tokens[2]) == 1) {
					if (atoi(tokens[2]))
					{
						if (atoi(tokens[2]) == 1) {
							printf("Please enter a value between 2-9 for multiple stepls.");
							getchar();
						}
						else {
							for (i = 0;i < atoi(tokens[2]);i++) {
								move(current_try, 2);
							}
						}
					}
					else {
						printf("Please enter a value between 2-9 for multiple stepls.");
						getchar();
					}
				}
				else {
					printf("Please enter a value between 2-9 for multiple stepls.");
					getchar();
				}
			}
			else {
				move(current_try, 2);
			}
		}
		else if (tokens[1] == NULL) {
			printf("Go where?");
			getchar();
		}
		else {
			printf("I did not understand that.");
			getchar();
		}
	}
	else if (strcmp(tokens[0],"grab") == 0) {
		grab(tokens, current_try);
	}
	else if (strcmp(tokens[0],"open") == 0) {
		open(tokens, current_try);
	}
	else if (strcmp(tokens[0],"use") == 0) {
		use(tokens, current_try);
	}
	else {
		printf("I did not understand what you meant by that!");
		getchar();
	}
}

void go(char(*tokens)[3], int current_try) {
	
}

void grab(char(*tokens)[3], int current_try) {

}

void open(char(*tokens)[3], int current_try) {

}

void use(char(*tokens)[3], int current_try) {

}




void move(int current_try, int direction) {//direction is an int, 1 means up, 2 is right, 3 is down, 4 is left


	if (direction == 1) {
		if (map[current_try][player_location[0] - 2][player_location[1]] == '|') {
			map[current_try][player_location[0]][player_location[1]] = ' ';
			player_location[0] -= 5;
			map[current_try][player_location[0]][player_location[1]] = '@'; 
		}
	}
	else if (direction == 3) {
		if (map[current_try][player_location[0] + 2][player_location[1]] == '|') {
			map[current_try][player_location[0]][player_location[1]] = ' ';
			player_location[0] += 5;
			map[current_try][player_location[0]][player_location[1]] = '@';
		}
	}
	else if (direction == 2) {
		if (map[current_try][player_location[0]][player_location[1] + 3] == '=') {
			map[current_try][player_location[0]][player_location[1]] = ' ';
			player_location[1] += 6;
			map[current_try][player_location[0]][player_location[1]] = '@';
		}
	}
	else if (direction == 4) {
		if (map[current_try][player_location[0]][player_location[1] - 3] == '=') {
			map[current_try][player_location[0]][player_location[1]] = ' ';
			player_location[1] -= 6;
			map[current_try][player_location[0]][player_location[1]] = '@';

		}
	}



}

void test_move(int current_try, int player_location[], int direction, int *v, int(*visited)[25]) {//direction is an int, 1 means up, 2 is right, 3 is down, 4 is left

	int i;
	int was = 0;
	int p = *v;
	int g;

	if (direction == 1) {
		if (map[current_try + 1][player_location[0] - 2][player_location[1]] == '|') {
			player_location[0] -= 5;
			for (i = 0;i <= p + 1;i++) {
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
		if (map[current_try + 1][player_location[0] + 2][player_location[1]] == '|') {
			player_location[0] += 5;
			for (i = 0;i <= p + 1;i++) {
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
		if (map[current_try + 1][player_location[0]][player_location[1] + 3] == '=') {
			player_location[1] += 6;
			for (i = 0;i <= p + 1;i++) {
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
		if (map[current_try + 1][player_location[0]][player_location[1] - 3] == '=') {
			player_location[1] -= 6;
			for (i = 0;i <= p + 1;i++) {
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