#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "randomization.h"


void input(int current_try);

void move(int current_try, int direction);

void test_move(int current_try, int player_location[], int direction, int *v, int(*visited)[25]);