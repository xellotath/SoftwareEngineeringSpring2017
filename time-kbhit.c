#include <stdio.h>
#include <time.h>

void delay(unsigned int mseconds);

int main(void) {

	int i, j, k;

	i = 0;

	for (;;) {

		delay(1000);

		if (_kbhit()) {
			break;
		}

		printf("test %d\n", i);
		i++;


		if (_kbhit()) {
			break;
		}




	}



	getchar();

	return 0;



}

void delay(unsigned int mseconds)
{
	clock_t time = mseconds + clock();
	while (time > clock());
}