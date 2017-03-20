#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "commands.h"

int player_location[2];
int chest_location[2];
int key_location[2];
int door_location[2];
int enemy_location[2];
int _location[2];


void get_center(int(*room_center)[25]) {

	int m; //row variable increment for room center
	int n; //column variable increment for room center
	int i2 = 0; //incrementation for room center array

	for (m = 0; m <= 20; m += 5) // loop to fill in room CENTERS
	{
		for (n = 0; n <= 24; n += 6)
		{
			room_center[0][i2] = 2 + m;
			room_center[1][i2] = 2 + n;
			room_center[2][i2] = i2 + 1;
			i2++;
		}
	}


}


void randomize(int current_try, int(*room_center)[25]) {

	int m2; //row variable increment for vertical pathway
	int n2; //column variable increment for vertical pathway
	int m3; //row variable increment for horizontal pathway
	int n3; //column variable increment for horizontal pathway
	int pv_count = 0; //counter of how many vertical pathways have been created
	int ph_count = 0; //counter of how many horizontal pathways have been created
	int i3 = 0; //incrementation for vertical pathway array
	int i4 = 0; //incrementation for horizontal pathway array



	srand(time(NULL));
	int p = rand() % 25;//picking random variable set from room center array	
	int c = rand() % 25;//picking another random variable to be used for chest location
	int k = rand() % 25;//picking random variable for key
	int t = rand() % 25;//picking random variable for door
	int e = rand() % 25;//picking random variable for enemy
	int pv = rand() % 20;//picking random variable for vertical pathways
	int ph = rand() % 20;//picing random variable for horizontal pathways

	int path_v[2][20];//array for vertical pathways
	for (m2 = 0; m2 <= 15; m2 += 5) //Loop to fill in vertical PATHWAYS
	{
		for (n2 = 0; n2 <= 24; n2 += 6)
		{
			path_v[0][i3] = 4 + m2;
			path_v[1][i3] = 1 + n2;
			i3++;
		}
	}

	int path_h[2][20]; //array for horizontal pathways
	for (m3 = 0; m3 <= 20; m3 += 5)//Loop to fill in horizontal PATHWAYS
	{
		for (n3 = 0; n3 <= 18; n3 += 6)
		{
			path_h[0][i4] = 2 + m3;
			path_h[1][i4] = 5 + n3;
			i4++;
		}
	}

	if (p == c || p == k || p == t || p == e)
	{
		p = rand() % 25;
	}

	if (c == p || c == k || c == t || c == e)
	{
		c = rand() % 25;
	}

	if (k == c || k == p || k == t || k == e)
	{
		k = rand() % 25;
	}

	if (t == p || t == c || t == k || t == e)
	{
		t = rand() % 25;
	}

	map[current_try][room_center[0][p]][room_center[1][p]] = '@'; //placing character
	map[current_try][room_center[0][c] - 1][room_center[1][c]] = 'C'; //placing chest
	map[current_try][room_center[0][k] + 1][room_center[1][k]] = 'K'; //placing key
	map[current_try][room_center[0][t]][room_center[1][t] + 1] = 'T'; //placing teleporter
	map[current_try][room_center[0][e]][room_center[1][e] - 1] = 'E'; //placing enemy
	player_location[0] = room_center[0][p];
	chest_location[0] = room_center[0][c] - 1;
	key_location[0] = room_center[0][k] + 1;
	door_location[0] = room_center[0][t];
	enemy_location[0] = room_center[0][e];
	player_location[1] = room_center[1][p];
	chest_location[1] = room_center[1][c];
	key_location[1] = room_center[1][k];
	door_location[1] = room_center[1][t] + 1;
	enemy_location[1] = room_center[1][e] - 1;

	for (pv_count = 0; pv_count <= 20; pv_count++) //loop creating vertical pathways
	{
		if (map[current_try][path_v[0][pv]][path_v[1][pv]] == '|') //if a path is already there generate a new random variable
		{
			pv = rand() % 20;
		}

		map[current_try][path_v[0][pv]][path_v[1][pv]] = '|';
		map[current_try][path_v[0][pv] + 1][path_v[1][pv]] = '|';
		map[current_try][path_v[0][pv]][path_v[1][pv] + 1] = '|';
		map[current_try][path_v[0][pv] + 1][path_v[1][pv] + 1] = '|';
	}

	for (ph_count = 0; ph_count <= 20; ph_count++) //loop creating horizontal pathways
	{
		if (map[current_try][path_h[0][ph]][path_h[1][ph]] == '=')//if a path is already there generate a new random variable
		{
			ph = rand() % 20;
		}

		map[current_try][path_h[0][ph]][path_h[1][ph]] = '=';
		//		map[path_h[0][ph-1]][path_h[1][ph]+1] = '=';
		//		map[path_h[0][ph+1]][path_h[1][ph]-1] = '=';
	}

	validity(current_try);

}

void randomize_2(int current_try, int(*room_center)[25]) {

	int m2; //row variable increment for vertical pathway
	int n2; //column variable increment for vertical pathway
	int m3; //row variable increment for horizontal pathway
	int n3; //column variable increment for horizontal pathway
	int pv_count = 0; //counter of how many vertical pathways have been created
	int ph_count = 0; //counter of how many horizontal pathways have been created
	int i3 = 0; //incrementation for vertical pathway array
	int i4 = 0; //incrementation for horizontal pathway array



	srand(time(NULL));
	int p = rand() % 25;//picking random variable set from room center array	
	int c = rand() % 25;//picking another random variable to be used for chest location
	int k = rand() % 25;//picking random variable for key
	int t = rand() % 25;//picking random variable for door
	int e = rand() % 25;//picking random variable for enemy
	int pv = rand() % 20;//picking random variable for vertical pathways
	int ph = rand() % 20;//picing random variable for horizontal pathways

	int path_v[2][20];//array for vertical pathways
	for (m2 = 0; m2 <= 15; m2 += 5) //Loop to fill in vertical PATHWAYS
	{
		for (n2 = 0; n2 <= 24; n2 += 6)
		{
			path_v[0][i3] = 4 + m2;
			path_v[1][i3] = 1 + n2;
			i3++;
		}
	}

	int path_h[2][20]; //array for horizontal pathways
	for (m3 = 0; m3 <= 20; m3 += 5)//Loop to fill in horizontal PATHWAYS
	{
		for (n3 = 0; n3 <= 18; n3 += 6)
		{
			path_h[0][i4] = 2 + m3;
			path_h[1][i4] = 5 + n3;
			i4++;
		}
	}

	if (p == c || p == k || p == t || p == e)
	{
		p = rand() % 25;
	}

	if (c == p || c == k || c == t || c == e)
	{
		c = rand() % 25;
	}

	if (k == c || k == p || k == t || k == e)
	{
		k = rand() % 25;
	}

	if (t == p || t == c || t == k || t == e)
	{
		t = rand() % 25;
	}

	map[current_try][room_center[0][p]][room_center[1][p]] = '@'; //placing character
	map[current_try][room_center[0][c] - 1][room_center[1][c]] = 'C'; //placing chest
	map[current_try][room_center[0][k] + 1][room_center[1][k]] = 'K'; //placing key
	map[current_try][room_center[0][t]][room_center[1][t] + 1] = 'T'; //placing teleporter
	map[current_try][room_center[0][e]][room_center[1][e] - 1] = 'E'; //placing enemy
	player_location[0] = room_center[0][p];
	chest_location[0] = room_center[0][c] - 1;
	key_location[0] = room_center[0][k] + 1;
	door_location[0] = room_center[0][t];
	enemy_location[0] = room_center[0][e];
	player_location[1] = room_center[1][p];
	chest_location[1] = room_center[1][c];
	key_location[1] = room_center[1][k];
	door_location[1] = room_center[1][t] + 1;
	enemy_location[1] = room_center[1][e] - 1;

	for (pv_count = 0; pv_count <= 50; pv_count++) //loop creating vertical pathways
	{
		if (map[current_try][path_v[0][pv]][path_v[1][pv]] == '|') //if a path is already there generate a new random variable
		{
			pv = rand() % 20;
		}

		map[current_try][path_v[0][pv]][path_v[1][pv]] = '|';
		map[current_try][path_v[0][pv] + 1][path_v[1][pv]] = '|';
		map[current_try][path_v[0][pv]][path_v[1][pv] + 1] = '|';
		map[current_try][path_v[0][pv] + 1][path_v[1][pv] + 1] = '|';
	}

	for (ph_count = 0; ph_count <= 50; ph_count++) //loop creating horizontal pathways
	{
		if (map[current_try][path_h[0][ph]][path_h[1][ph]] == '=')//if a path is already there generate a new random variable
		{
			ph = rand() % 20;
		}

		map[current_try][path_h[0][ph]][path_h[1][ph]] = '=';
	}

	for (int i = 0;i < 25;i++) {
		printf("%s\n", map[current_try][i]);
	}

	validity(current_try);


}


int validity(int current_try) {
	int test[2];
	int v = 0;
	int t = 0;
	int visited[2][25];
	int l;

	srand(time(NULL));
	l = (rand() % 4) + 1;

	test[0] = 2;
	test[1] = 2;

	visited[0][0] = 2;
	visited[1][0] = 2;

	for (;;) {
		l = (rand() % 5) + 1;
		move(current_try, test, l, &v, visited);
		l = (rand() % 5) + 1;
		move(current_try, test, l, &v, visited);
		l = (rand() % 5) + 1;
		move(current_try, test, l, &v, visited);
		l = (rand() % 5) + 1;
		move(current_try, test, l, &v, visited);


		if (v == 24) {
			printf("YES");
			getchar();
			return 1;
		}
		t++;
		if (t == 500) {
			printf("NO");
			getchar();
			return 0;
		}
	}





}