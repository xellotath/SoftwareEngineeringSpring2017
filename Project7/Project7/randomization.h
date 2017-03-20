#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "randomization.h"

extern int player_location[2];
extern int chest_location[2];
extern int key_location[2];
extern int door_location[2];
extern int enemy_location[2];
extern int _location[2];

void get_center(int(*)[25]);
void randomize(int current_try, int(*room_center)[25]);
void randomize_2(int current_try, int(*room_center)[25]);
int validity(int current_try);

