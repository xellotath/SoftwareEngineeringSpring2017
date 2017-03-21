#include "map.h"

//an array of arrays of strings is used to display the map. the uppermost level of the array, and the first of them , holds the original map below.
//whenever the map is to be randomized, a new one is copied in a different level of the array, indexed by current_level
//if the randomization is not solvable, then a new instance of the map will be created 

char map[9][25][30] =	
{
	"----- ----- ----- ----- -----",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"----- ----- ----- ----- -----",
	"----- ----- ----- ----- -----",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"----- ----- ----- ----- -----",
	"----- ----- ----- ----- -----",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"----- ----- ----- ----- -----",
	"----- ----- ----- ----- -----",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"----- ----- ----- ----- -----",
	"----- ----- ----- ----- -----",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"|   | |   | |   | |   | |   |",
	"----- ----- ----- ----- -----"
};