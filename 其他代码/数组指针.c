#include <stdio.h>
#include <stdlib.h>

int main()
{
	int b[][2] = {1, 2, 3, 4};
	int(*p)[2] = b;

	//*p[1] = 30;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			printf("%d", p[i][j]);

	return 0;
}