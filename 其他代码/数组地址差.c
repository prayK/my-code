#include <stdio.h>

int main(void)
{
	int a[3] = {1, 2, 3};
	int* p1 = a;
	int* p2 = &a[2];

	printf("%d\n", &a[2] - &a[0]);
	printf("%p, %p\n", &a[2], &a[0]);
	printf("%d\n", p2 - p1);
	
	return 0;
}