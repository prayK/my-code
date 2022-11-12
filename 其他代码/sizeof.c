#include <stdio.h>

int main()
{
	int a = 0;
	int b = sizeof(a++);

	printf("a = %d, b = %d\n", a, b);

	return 0;
}
