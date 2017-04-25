#include "Source.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma disable(warning: 4996)

void _delay(unsigned int ms);

int algo(int current_try, int(*room_center)[25]);//algo prototype

int a_switch = 0;

int delay_ms = 1000; //delay will be passed to the delay function, and is in miliseconds
FILE *fp;			 //file pointer
time_t now;			 //time_t variable for getting current time
char date_time[250]; //string to hold the date filename for logs
char date_time_replay[250];//string to hold the date filename for replays
int pause = 0;
int stop = 0;
int steps = 0;
int forward = 0;
int back = 0;
unsigned int ms = 1500;
int menu = 0; //menu selection variable
char yn = 0; //yes or no variable
char latest_replays[3][30] = {{NULL},{NULL},{NULL}}; //array to store replay files

int main(void)
{
	now = time(NULL);
	struct tm *t = localtime(&now);
	strftime(date_time, sizeof(date_time), "Log_%d-%m-%y_%H-%M-%S.txt", t);
	fp = fopen(date_time, "w+");



	int current_try = 1;//this holds the number of tries it has taken for a map to be generated
	int i = 0;//loop variable
	int j = 0;//loop variable


	int room_center[3][25];//declaration of room centers' array

	get_center(room_center);//fill that array


	for (;;)
	{
		if (menu == 0) {
			printf("___________\n"
				"|Main Menu|\n"
				"-----------\n\n"
				"1.Play\n"
				"2.Watch a Replay\n"
				"3.Exit\n\n"
				"Your Choice: ");
		}
		scanf("%d", &menu);

		if (menu == 1) { //activates gameplay

			for (;current_try < 100;current_try++) {
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

				system("cls");//screen is cleared and then map gets reprinted to reflect changes made after a command

				for (i = 0;i < 25;i++) {
					printf("%s\n", map[current_try][i]);
				}

				printf("\n");

				if ((map[current_try][player_location[0] - 1][player_location[1] - 1] == 'E') || map[current_try][player_location[0]][player_location[1] - 1] == 'E') {
					printf("The friendly 'E' letters showed you the way out. But you came back.");
					locked_door = 1;
					opened_chest = 0;
					locked_chest = 1;
					has_key = 0;
					map[current_try][key_location[0]][key_location[1]] = 'K';
					map[current_try][chest_location[0]][chest_location[1]] = 'C';
					map[current_try][player_spawn_location[0]][player_spawn_location[1]] = '@';
					map[current_try][player_location[0]][player_location[1]] = ' ';
					player_location[0] = player_spawn_location[0];
					player_location[1] = player_spawn_location[1];
					map[current_try][enemy2_location[0]][enemy2_location[1]] = ' ';
					map[current_try][enemy2_spawn_pair[0]][enemy2_spawn_pair[1]] = 'E';
					enemy2_location[0] = enemy2_spawn_pair[0];
					enemy2_location[1] = enemy2_spawn_pair[1];
					map[current_try][enemy_location[0]][enemy_location[1]] = ' ';
					map[current_try][enemy_spawn_pair[0]][enemy_spawn_pair[1]] = 'E';
					enemy_location[0] = enemy_spawn_pair[0];
					enemy_location[1] = enemy_spawn_pair[1];
					now = time(NULL);
					struct tm *t = localtime(&now);
					strftime(date_time, sizeof(date_time), "%H-%M-%S - Game event - Player death - "
						"Player has come in contact with an enemy - Resetting game using the same map", t);
					fprintf(fp, "%s\n", date_time);
				}

				input(current_try);//accepts input from the player and checks it against the defaults
								   //an output may or may not be explicitly printed

				if (game_ended == 1) {
					printf("Thank you for playing!");
					getchar();
					fclose(fp);
					system("cls");
					menu = 0;
					break;
				}
			}
		}
		
		else if (menu == 2) { //activates replay

			system("cls");//clear screen

			if (latest_replays[0][0] == NULL && latest_replays[1][0] == NULL && latest_replays[2][0] == NULL) {
				printf("\n"
					"___________\n"
					"| Replays |\n"
					"-----------\n\n"
					"No availabe replays!\n"
					"Press any key to be redirected to main menu\n\n");

				getchar();
				getchar();
				menu = 0;
				system("cls");
				continue;
			}
			
			else if (latest_replays[1][0] == NULL && latest_replays[2][0] == NULL) {
				printf("\n"
					"___________\n"
					"| Replays |\n"
					"-----------\n\n"
					"Select one of the available replays:\n"
					"1.\n"
					"2.Return to main menu\n\n"
					"Your choice: ");

				scanf("%d", &menu);

				if (menu == 1) {

				}
				else if (menu == 2) {
					system("cls");
					menu = 0;
					continue;
				}
				else {
					printf("Please enter an integer 1 - 2 for menu selection");
					scanf("%d", &menu);
				}
			}

			else if (latest_replays[2][0] == NULL) {
				printf("\n"
					"___________\n"
					"| Replays |\n"
					"-----------\n\n"
					"Select one of the available replays:\n"
					"1.\n"
					"2.\n"
					"3.Return to main menu\n\n"
					"Your choice: ");
				scanf("%d", &menu);
				if (menu == 1) {

				}
				else if (menu == 2) {

				}
				else if (menu == 3) {
					system("cls");
					menu = 0;
					continue;
				}
				else {
					printf("Please enter an integer 1 - 3 for menu selection");
					scanf("%d", &menu);
				}
			}
			
			else {
				printf("\n"
					"___________\n"
					"| Replays |\n"
					"-----------\n\n"
					"Select one of the available replays:\n"
					"1.\n"
					"2.\n"
					"3.\n"
					"4.Return to main menu\n\n"
					"Your choice: ");
				scanf("%d", &menu);
				if (menu == 1) {

				}
				else if (menu == 2) {

				}
				else if (menu == 3) {

				}
				else if (menu == 4) {
					system("cls");
					menu = 0;
					continue;
				}
				else {
					printf("Please enter an integer 1 - 4 for menu selection");
					scanf("%d", &menu);
				}
			}

			replay_mode = 1;
			while (steps != sc) {

				/*for (i = 0; i < 35; i++) {
				_delay(ms);
				if (_kbhit()) {
				input(0);
				}
				if (i == 34) {
				stop = 1;
				}
				}*/

				if (stop == 1) {
					break;
				}


				if (pause == 0) {
					system("cls");
					for (i = 0;i < 25;i++) {
						printf("%s\n", replay_map[steps][i]);
					}
					_delay(ms);

					if (_kbhit()) {
						input(0);
					}
					steps++;
				}
				else {
					input(0);
					if (back == 1 || forward == 1) {
						system("cls");
						for (i = 0;i < 25;i++) {
							printf("%s\n", replay_map[steps][i]);
						}
						forward = 0;
						back = 0;
					}
				}
			}

			menu = 0;
			break;
		}

		else if (menu == 3) { //exits game
			system("cls");
			fclose(fp);
			return 0;
		}

		else{
			printf("Please enter an integer 1 - 3 for menu selection");
			scanf("%d", &menu);
		}

	}

}


int algo(int current_try, int(*room_center)[25]) {
	//this is the function that switches algorithms. is called indefinitely.
	//however, at least one of the maps created from randomize_2 is bound to be valid
	//before current_try exceeds the capacity of char map(100).

	//it calls a series of int functions that will ultimately return 1 if the map is valid
	//and 0 for invalid. every 4 tries it switches algorithms




	if (a_switch == 0) {
		if ((current_try % 4) == 0) {

			now = time(NULL);
			struct tm *t = localtime(&now);
			strftime(date_time, sizeof(date_time), "%H-%M-%S - Randomization algorithm couldn't produce proper maze - "
				"[int randomize()] - Retrying one last time and then switching to [int randomize_2()]", t);
			fprintf(fp, "%s\n", date_time);

			a_switch = 1;
		}
		return randomize(current_try, room_center);


	}
	else {
		if (current_try % 4 == 0) {

			now = time(NULL);
			struct tm *t = localtime(&now);
			strftime(date_time, sizeof(date_time), "%H-%M-%S - Randomization algorithm couldn't produce proper maze - "
				"[int randomize_2()] - Retrying one last time and then switching to [int randomize()]", t);
			fprintf(fp, "%s\n", date_time);



			a_switch = 0;
		}
		return randomize_2(current_try, room_center);
	}


}

void _delay(unsigned int mseconds) //whenever this function is called it will cause a delay of "mseconds" miliseconds
{
	clock_t time = mseconds + clock();	//time to campare against current time
	while (time > clock());				//when current time is target time, stop
}