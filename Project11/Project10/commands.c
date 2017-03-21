#include "commands.h"


int locked_door = 1;
int chest_code;
int opened_chest = 0;
int has_key = 0;
int used_marker = 0;

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
		if (tokens[1] != NULL) {
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
		else {
			printf("Go where?");
		}
	}
	else if (strcmp(tokens[0],"grab") == 0) {
		if (strcmp(tokens[1], "key") == 0) {
			if (tokens[2] != NULL) {
				printf("I did not understand that.");
			}
			else if ((player_location[0] + 1) == key_location[0] && player_location[1] == key_location[1] && has_key == 0) {
				//if key is in the room and player doesn't have it remove it
				map[current_try][key_location[0]][key_location[1]] = ' ';
				has_key = 1;//key grabbed
				printf("You got the key!");
			}
			else {
				printf("There's no key to grab!");
			}
		}
		else {
			printf("I did not understand that.");
		}
	}
	else if (strcmp(tokens[0],"open") == 0) {
		if (strcmp(tokens[1], "door") == 0) {
			if (tokens[2] != NULL) {
				printf("I did not understand that.");
				getchar();
			}
			else if((player_location[0]) == door_location[0] && (player_location[1]+1) == door_location[1] && locked_door == 0) {
				printf("You escaped! You have been teleported to safety!");
			}
			else if ((player_location[0]) == door_location[0] && (player_location[1] + 1) == door_location[1] && locked_door == 1) {
				printf("The door is locked!");
			}
			else {
				printf("There's no door to open!");
			}
		}else if (strcmp(tokens[1], "chest") == 0) {
			if (tokens[2] != NULL) {
				printf("I did not understand that.");
				getchar();
			}
			else {
				//open chest			
			}
		}
		else {
			printf("I did not understand that.");
			getchar();
		}
	}
	else if (strcmp(tokens[0],"use") == 0) {
		if (strcmp(tokens[1], "key") == 0) {
			if (tokens[2] != NULL) {
				printf("I did not understand that.");
				getchar();
			}
			else {
				if ((player_location[0]) == door_location[0] && (player_location[1] + 1) == door_location[1] && locked_door == 1 && has_key == 1) {
					locked_door = 0;
					printf("The door has been unlocked!");
				}
				else if ((player_location[0]) == door_location[0] && (player_location[1] + 1) == door_location[1] && locked_door == 0 && has_key == 1) {
					printf("The door has been locked again!");
					locked_door = 1;
				}
				else if(has_key == 1){
					printf("There's nothing to use the key with!");
				}
				else {
					printf("You don't have a key!");
				}
			}
		}
		else if (strcmp(tokens[1], "marker") == 0) {
			if (tokens[2] != NULL) {
				printf("I did not understand that.");
				getchar();
			}
			else {
				if (used_marker == 0) {
					mark_location[0] = player_location[0] + 1;
					mark_location[1] = player_location[1] - 1;
					map[current_try][mark_location[0]][mark_location[1]] = 'M';
					used_marker = 1;
				}
				else {
					map[current_try][mark_location[0]][mark_location[1]] = ' ';
					mark_location[0] = player_location[0] + 1;
					mark_location[1] = player_location[1] - 1;
					map[current_try][player_location[0] + 1][player_location[1] - 1] = 'M';
				}
			}
		}
		else {
			printf("I did not understand that.");
			getchar();
		}
	}
	else {
		printf("I did not understand what you meant by that!");
		getchar();
	}
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