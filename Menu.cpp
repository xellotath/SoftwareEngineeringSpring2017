#include <stdio.h>
void unecessary(int n);
int main()
{
	int num = 0;
	printf("Welcome to the Game \n");
	printf("\n Main menu \n", "1. Play the Game \n","3. Help \n "" 2. Quit \n");
	printf(" Choose a number: ");
	scanf("%d", &num);
	unecessary(num);
}
	
	void unecessary(int n)
	{
	if(n == 1)
			printf("1 ");
	else 
			printf(" 2");

			getchar();
	}
