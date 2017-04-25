#include "commands.h"


int locked_door = 1;//is the door locked?
int chest_code;//the code of the chest
int locked_chest = 1;//hmm
int opened_chest = 0;//self explanatory
int has_key = 0;//do you have the key?
int used_marker = 0;//checks if marker was used
int game_ended = 0;//main endless loop breaks with this
char chest_code_string[3];//holds the chest code
int failprint = 0;//ensures one print
int replay_mode = 0; //becomes 1 if the ser is watcing a replay, 0 when he returns to the main menu
char replay_map[250][25][30]; //array to store locations of all elements in play
int sc = 0; //counter variable for successful commands
int algo1fail = 0;
int algo2fail = 0;
int first_export = 1;


void input(int current_try) {

	int i = 0;
	char user_input[100];
	char *tokens[3] = { NULL, NULL, NULL };
	char *temp;

	gets(user_input);

	temp = strtok(user_input, " ");

	while (temp != NULL && i<3)
	{
		tokens[i++] = temp;
		temp = strtok(NULL, " ");
	}

	if (tokens[0] != NULL) {//checks if nothing has been entered

		if (strcmp(tokens[0], "go") == 0) {
			if (tokens[1] != NULL) {//checks if nothing followed the first word
				if (replay_mode == 1)
				{
					if (strcmp(tokens[1], "forward") == 0)
					{
						if (tokens[2] != NULL)// checking for third word in string
						{
							if (atoi(tokens[2])) //will not enter loop if third word is not an interger
							{
								steps = steps + atoi(tokens[2]);
							}
							forward = 1;
						}
						else {
							printf("Please try command again with an integer after 'forward'");
							getchar();
						}


					}
					else if (strcmp(tokens[1], "back") == 0)
					{
						if (tokens[2] != NULL) //checking for third word in string
						{
							if (atoi(tokens[2])) //will not enter loop if third word is not an integer
							{
								steps = steps - atoi(tokens[2]);
							}
							back = 1;

						}
						else {
							printf("Please try command again with an integer after 'back'");
							getchar();
						}
					}
					else if (strcmp(tokens[1], "faster") == 0)
					{
						ms = ms - 300;
					}
					else if (strcmp(tokens[1], "slower") == 0)
					{
						ms = ms + 300;
					}
				}
				else if (strcmp(tokens[1], "up") == 0) {
					if (tokens[2] != NULL) {//checks if there is a third word
						if (strlen(tokens[2]) == 1) {
							if (atoi(tokens[2]))
							{
								if (atoi(tokens[2]) == 1) {
									printf("Please enter a value between 2-9 for multiple stepls.");
									getchar();

								}
								else {
									enemy_move(current_try);//first the enemies move, then the player. contact with enemies is checked after all moves are done
									enemy2_move(current_try);
									for (i = 0;i < atoi(tokens[2]);i++) {
										move(current_try, 1);
									}
									_export(current_try);
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
						enemy_move(current_try);
						enemy2_move(current_try);
						move(current_try, 1);
						_export(current_try);
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
									enemy_move(current_try);
									enemy2_move(current_try);
									for (i = 0;i < atoi(tokens[2]);i++) {
										move(current_try, 3);
									}
									_export(current_try);
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
						enemy_move(current_try);
						enemy2_move(current_try);
						move(current_try, 3);
						_export(current_try);
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
									enemy_move(current_try);
									enemy2_move(current_try);
									for (i = 0;i < atoi(tokens[2]);i++) {
										move(current_try, 4);
									}
									_export(current_try);
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
						enemy_move(current_try);
						enemy2_move(current_try);
						move(current_try, 4);
						_export(current_try);
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
									enemy_move(current_try);
									enemy2_move(current_try);
									for (i = 0;i < atoi(tokens[2]);i++) {
										move(current_try, 2);
									}
									_export(current_try);
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
						enemy_move(current_try);
						enemy2_move(current_try);
						move(current_try, 2);
						_export(current_try);
					}
				}
				else if (tokens[1] == NULL) {
					printf("Go where?");
				}
				else {
					printf("I did not understand that.");
					getchar();

				}
			}
			else {
				printf("Go where?");
				getchar();

			}
		}
		else if (strcmp(tokens[0], "grab") == 0) {
			if (tokens[1] != NULL) {
				if (strcmp(tokens[1], "key") == 0) {
					if (tokens[2] != NULL) {
						printf("I did not understand that.");
						getchar();

					}
					else if ((player_location[0] + 1) == key_location[0] && player_location[1] == key_location[1] && has_key == 0) {
						//if key is in the room and player doesn't have it remove it
						map[current_try][key_location[0]][key_location[1]] = ' ';
						has_key = 1;//key grabbed
						printf("You got the key!");
						getchar();
						_export(current_try);
					}
					else {
						printf("There's no key to grab!");
						getchar();

					}
				}
				else {
					printf("I did not understand that.");
					getchar();

				}
			}
			else {
				printf("Grab what?");
				getchar();

			}
		}
		else if (strcmp(tokens[0], "open") == 0) {
			if (tokens[1] != NULL) {
				if (strcmp(tokens[1], "door") == 0) {
					if (tokens[2] != NULL) {
						printf("I did not understand that.");
						getchar();

					}//player can only escape if he has unlocked the door and they have opened the chest
					else if ((player_location[0]) == door_location[0] && (player_location[1] + 1) == door_location[1] && locked_door == 0 && opened_chest == 1) {
						printf("You escaped! You have been teleported to safety!");
						getchar();

						game_ended = 1;
					}
					else if ((player_location[0]) == door_location[0] && (player_location[1] + 1) == door_location[1] && locked_door == 0 && opened_chest == 0) {
						printf("I think there is a super-important treasure chest that I should open before I leave.");
						getchar();

					}
					else if ((player_location[0]) == door_location[0] && (player_location[1] + 1) == door_location[1] && locked_door == 1) {
						printf("The door is locked!");
						getchar();

					}
					else {
						printf("There's no door to open!");
						getchar();

					}
				}
				else if (strcmp(tokens[1], "chest") == 0) {
					if (tokens[2] != NULL) {
						printf("I did not understand that.");
						getchar();

					}
					else {
						if (locked_chest == 0) {
							map[current_try][chest_location[0]][chest_location[1]] = 'O';
							printf("It's empty! :D");
							opened_chest = 1;
							_export(current_try);
						}
						else {
							printf("It has a lock and a keypad!");
							getchar();

						}
					}
				}
				else {
					printf("I did not understand that.");
					getchar();

				}
			}
			else {
				printf("Open what?");
				getchar();

			}
		}
		else if (strcmp(tokens[0], "use") == 0) {
			if (tokens[1] != NULL) {
				if (strcmp(tokens[1], "key") == 0) {
					if (tokens[2] != NULL) {
						printf("I did not understand that.");
						getchar();

					}
					else {
						if ((player_location[0]) == door_location[0] && (player_location[1] + 1) == door_location[1] && locked_door == 1 && has_key == 1) {
							locked_door = 0;
							printf("The door has been unlocked!");
							getchar();

						}
						else if ((player_location[0]) == door_location[0] && (player_location[1] + 1) == door_location[1] && locked_door == 0 && has_key == 1) {
							printf("The door has been locked again!");
							getchar();
							locked_door = 1;
						}
						else if (has_key == 1) {
							printf("There's nothing to use the key with!");
							getchar();

						}
						else {
							printf("You don't have a key!");
							getchar();

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
							_export(current_try);
						}
						else {
							map[current_try][mark_location[0]][mark_location[1]] = ' ';
							mark_location[0] = player_location[0] + 1;
							mark_location[1] = player_location[1] - 1;
							map[current_try][player_location[0] + 1][player_location[1] - 1] = 'M';
							_export(current_try);
						}
					}
				}
				else if (strcmp(tokens[1], chest_code_string) == 0) {

					printf("The chest unlocked!");
					getchar();

					locked_chest = 0;

				}
				else if (replay_mode == 1)
				{
					if (strcmp(tokens[1], "pause") == 0)
					{
						pause = 1;
						input(0);
					}
					else if (strcmp(tokens[1], "resume") == 0)
					{
						pause = 0;
					}
					else if (strcmp(tokens[1], "stop") == 0)
					{
						stop = 1;
					}
				}
				else {
					printf("I did not understand that.");
					getchar();

				}
			}
			else {
				printf("Use what?");
				getchar();

			}
		}
		else if (strcmp(tokens[0], "look") == 0) {
			if (tokens[1] != NULL) {
				if (strcmp(tokens[1], "around") == 0) {
					if (tokens[2] != NULL) {
						printf("I did not understand that.");
						getchar();

					}
					else {
						if (player_location[0] == password_locations[0][0] && player_location[1] == password_locations[1][0]) {
							printf("There's a number on the wall: %d", password_locations[2][0]);
							getchar();

						}
						else if (player_location[0] == password_locations[0][1] && player_location[1] == password_locations[1][1]) {
							printf("There's a number on the wall: %d", password_locations[2][1]);
							getchar();

						}
						else if (player_location[0] == password_locations[0][2] && player_location[1] == password_locations[1][2]) {
							printf("There's a number on the wall: %d", password_locations[2][2]);
							getchar();

						}
						else {
							printf("I don't see anything you don't see");
							getchar();

						}
					}
				}
			}
			else {
				printf("Around maybe?");
				getchar();

			}
		}
		else if (strcmp(tokens[0], "exit") == 0) {
			game_ended = 1;
		}
		else if (strcmp(tokens[0], "passkey") == 0) {
			printf("The password is: %d %d %d", password_locations[2][0], password_locations[2][1], password_locations[2][2]);
			getchar();
		}
		else if (strcmp(tokens[0], "locations") == 0) {
			printf("The locations of the passwords are:\n %d %d \n %d %d \n %d %d ",password_locations[0][0], password_locations[1][0], password_locations[0][1], password_locations[1][1], password_locations[0][2], password_locations[1][2]);
			getchar();
		}
		else if (strcmp(tokens[0], "picklock") == 0) {
			has_key = 1;
			if ((player_location[0]) == door_location[0] && (player_location[1] + 1) == door_location[1] && locked_door == 1 && has_key == 1) {
				locked_door = 0;
				printf("Keys are for casuals! Door has been unlocked!s");
				getchar();
			}
		}
		else {
			printf("I did not understand that");
			getchar();

		}
	}
}





void move(int current_try, int direction) {//direction is an int, 1 means up, 2 is right, 3 is down, 4 is left


	if (direction == 1) {
		if (map[current_try][player_location[0] - 2][player_location[1]] == '|') {//checks if there is a pathway
			map[current_try][player_location[0]][player_location[1]] = ' ';//removes the player from the previous position
			player_location[0] -= 5;//updates player location
			map[current_try][player_location[0]][player_location[1]] = '@'; //moves player to new position
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


void enemy_move(int current_try) {//direction is an int, 1 means up, 2 is right, 3 is down, 4 is left

	int direction;
	srand(time(NULL));

	direction = (rand() % 4) + 1;//moves first enemy towards a random direction every time

	if (direction == 1) {
		if (map[current_try][enemy_location[0] - 2][enemy_location[1] + 1] == '|') {
			map[current_try][enemy_location[0]][enemy_location[1]] = ' ';
			enemy_location[0] -= 5;
			map[current_try][enemy_location[0]][enemy_location[1]] = 'E';
		}
	}
	else if (direction == 3) {
		if (map[current_try][enemy_location[0] + 2][enemy_location[1] + 1] == '|') {
			map[current_try][enemy_location[0]][enemy_location[1]] = ' ';
			enemy_location[0] += 5;
			map[current_try][enemy_location[0]][enemy_location[1]] = 'E';
		}
	}
	else if (direction == 2) {
		if (map[current_try][enemy_location[0]][enemy_location[1] + 4] == '=') {
			map[current_try][enemy_location[0]][enemy_location[1]] = ' ';
			enemy_location[1] += 6;
			map[current_try][enemy_location[0]][enemy_location[1]] = 'E';
		}
	}
	else if (direction == 4) {
		if (map[current_try][enemy_location[0]][enemy_location[1] - 2] == '=') {
			map[current_try][enemy_location[0]][enemy_location[1]] = ' ';
			enemy_location[1] -= 6;
			map[current_try][enemy_location[0]][enemy_location[1]] = 'E';

		}
	}



}

void enemy2_move(int current_try) {//direction is an int, 1 means up, 2 is right, 3 is down, 4 is left

	int direction;

	//gets votes from the 3 algorithms
	int a = enemy2_algo(current_try);
	int b = enemy2_algo2(current_try);
	int c = enemy2_algo3(current_try);

	//sees if they agree
	if (a == b == c) {
		direction = c;
	}
	else if (a == c) {
		direction = c;



		algo2fail++;//fails one algorithm if it disagrees twice
	}
	else if (b == c) {
		direction = c;
		algo1fail++;//fails one algorithm if it disagrees twice
	}
	else {//respawns enemy 2 if system fails



		algo1fail = 0;
		algo2fail = 0;
		map[current_try][enemy2_location[0]][enemy2_location[1]] = ' ';
		map[current_try][enemy2_spawn_pair[0]][enemy2_spawn_pair[1]] = 'E';
	}




	if (direction == 1) {
		if (map[current_try][enemy2_location[0] - 1][enemy2_location[1] + 1] == '|') {
			map[current_try][enemy2_location[0]][enemy2_location[1]] = ' ';
			enemy2_location[0] -= 5;
			map[current_try][enemy2_location[0]][enemy2_location[1]] = 'E';
		}
	}
	else if (direction == 3) {
		if (map[current_try][enemy2_location[0] + 3][enemy2_location[1] + 1] == '|') {
			map[current_try][enemy2_location[0]][enemy2_location[1]] = ' ';
			enemy2_location[0] += 5;
			map[current_try][enemy2_location[0]][enemy2_location[1]] = 'E';
		}
	}
	else if (direction == 2) {
		if (map[current_try][enemy2_location[0] + 1][enemy2_location[1] + 4] == '=') {
			map[current_try][enemy2_location[0]][enemy2_location[1]] = ' ';
			enemy2_location[1] += 6;
			map[current_try][enemy2_location[0]][enemy2_location[1]] = 'E';
		}
	}
	else if (direction == 4) {
		if (map[current_try][enemy2_location[0] + 1][enemy2_location[1] - 2] == '=') {
			map[current_try][enemy2_location[0]][enemy2_location[1]] = ' ';
			enemy2_location[1] -= 6;
			map[current_try][enemy2_location[0]][enemy2_location[1]] = 'E';

		}
	}



}


void test_move(int current_try, int player_location[], int direction, int *v, int(*visited)[25]) {//direction is an int, 1 means up, 2 is right, 3 is down, 4 is left

																								  //attemps to traverse all rooms on the map, if a new room is entered v is incremented

	int i;
	int was = 0;//becomes 1 if room has been entered before
	int p = *v;//counter passed from caller
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

int enemy2_algo(int current_try) {//enemy 2 moving algorithm that focuses on chasing the player firstly horizontally and then vertically


	if ((enemy2_location[1] + 1 < player_location[1]) && map[current_try][enemy2_location[0] + 1][enemy2_location[1] + 4] == '=') {
		return 2;
	}
	else if ((enemy2_location[1] + 1 > player_location[1]) && map[current_try][enemy2_location[0] + 1][enemy2_location[1] - 2] == '=') {
		return 4;
	}
	else if ((enemy2_location[0] + 1 > player_location[0]) && map[current_try][enemy2_location[0] - 1][enemy2_location[1] + 1] == '|') {
		return 1;
	}
	else if ((enemy2_location[0] + 1 < player_location[0]) && map[current_try][enemy2_location[0] + 3][enemy2_location[1] + 1] == '|') {
		return 3;
	}



}

int enemy2_algo2(int current_try) {//enemy 2 moving algorithm that focuses on chasing the player firstly verically and then horizontally

	if ((enemy2_location[0] + 1 > player_location[0]) && map[current_try][enemy2_location[0] - 1][enemy2_location[1] + 1] == '|') {
		return 1;
	}
	else if ((enemy2_location[0] + 1 < player_location[0]) && map[current_try][enemy2_location[0] + 3][enemy2_location[1] + 1] == '|') {
		return 3;
	}
	else if ((enemy2_location[1] + 1 < player_location[1]) && map[current_try][enemy2_location[0] + 1][enemy2_location[1] + 4] == '=') {
		return 2;
	}
	else if ((enemy2_location[1] + 1 > player_location[1]) && map[current_try][enemy2_location[0] + 1][enemy2_location[1] - 2] == '=') {
		return 4;
	}

}

int enemy2_algo3(int current_try) {

	//enemy 2 moving algorithm, essentially this will always agree with one of the other two algorithms,
	//however, the one that it agrees with depends on how many times it took the maze to be randomized,
	//essentially giving the movement style of enemy 2 some randomization of its own.

	int mod;


	if ((algo1fail < 2) && (algo2fail < 2)) {//fails one algorithm if it disagrees twice
		mod = current_try % 2;
		if (mod == 1) {
			return enemy2_algo2(current_try);
		}
		else {
			return enemy2_algo(current_try);
		}
	}
	else if (algo1fail >= 2) {
		if (failprint == 0) {
			now = time(NULL);
			struct tm *t = localtime(&now);
			strftime(date_time, sizeof(date_time), "%H-%M-%S - Enemy \"horizontal\" pathfinding algorithm failed - "
				"[int enemy2_algo()]. It will not be used again for this run.", t);
			fprintf(fp, "%s\n", date_time);
			failprint = 1;
		}

		return enemy2_algo2(current_try);
	}
	else if (algo2fail >= 2) {
		if (failprint == 0) {
			now = time(NULL);
			struct tm *t = localtime(&now);
			strftime(date_time, sizeof(date_time), "%H-%M-%S - Enemy \"vertical\" pathfinding algorithm failed - "
				"[int enemy2_algo2()]. It will not be used again for this run.", t);
			fprintf(fp, "%s\n", date_time);
			failprint = 1;
		}

		return enemy2_algo(current_try);
	}


}

void _export(int ct)
{
	for (int i = 0; i <= 25; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			replay_map[sc][i][j] = map[ct][i][j];
		}
	}
	sc++;
}