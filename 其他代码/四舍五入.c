#include <stdio.h>

int main(void)
{
	float a = 3.4f;
	scanf("%f", &a);
	
	int b = (int)a;

	if(a - b > 0.5)
		b = b + 1;

	printf("%d\n", b);	
	
	return 0;
}