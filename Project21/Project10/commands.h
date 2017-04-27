#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "map.h"
#include "randomization.h"
#include "Source.h"


extern int locked_door;
extern int chest_code;
extern int opened_chest;
extern int has_key;
extern int used_marker;
extern int game_ended;
extern int locked_chest;
extern int replay_mode;
extern int sc;
extern char replay_map[250][25][30];

extern char *replay_commands[250];

extern char chest_code_string[3];

void input(int current_try);

void move(int current_try, int direction);

void enemy_move(int current_try);

void enemy2_move(int current_try);

int enemy2_algo(int current_try);

int enemy2_algo2(int current_try);

int enemy2_algo3(int current_try);

void test_move(int current_try, int player_location[], int direction, int *v, int(*visited)[25]);

void _export(int);