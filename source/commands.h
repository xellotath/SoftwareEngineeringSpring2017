#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "randomization.h"

void move(int current_try, int player_location[], int direction, int *v, int(*visited)[25]);