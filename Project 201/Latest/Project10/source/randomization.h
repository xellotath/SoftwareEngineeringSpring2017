#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "commands.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

extern int player_location[2];
extern int chest_location[2];
extern int key_location[2];
extern int door_location[2];
extern int enemy_location[2];
extern int mark_location[2];
extern int enemy2_location[2];
extern int enemy2_spawn_pair[2];
extern int password_locations[3][3];
extern int player_spawn_location[2];
extern int enemy_spawn_pair[2];


void get_center(int(*)[25]);
int randomize(int current_try, int(*room_center)[25]);
int randomize_2(int current_try, int(*room_center)[25]);
int validity(int current_try);

