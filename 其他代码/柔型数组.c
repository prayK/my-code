#include <stdio.h>
#include <malloc.h>

struct creat
{
	int len;
	int array[];
};

struct creat* creatsoftarray(int size)
{
	struct creat* ret = NULL;

	if(size > 0)
	{
		ret = (struct creat*)malloc(sizeof(struct creat) + sizeof(int) * size);
		ret->len = size;
	}
	for(int i=0; i<size; i++)
	{
		ret->array[i] = i + 1;
	}
	return ret;
}

void freesoftarray(struct creat* array)
{
	free(array);
}

int main(void)
{
	struct creat* p = creatsoftarray(10);
	
	if(p != NULL)
	{
		for(int i=0; i<10; i++)
		{
			printf("%d\n", p->array[i]);
		}
	}	
	freesoftarray(p);

	return 0;
}