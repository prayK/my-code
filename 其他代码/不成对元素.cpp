#include <iostream>
#include <malloc.h>

using namespace std;

int first_one_bit(unsigned int v)
{
    int ret = 0;
    
    while( (v != 0) && ((v & 1) == 0) )
    {
        v = v >> 1;
        ret++;
    }
    
    return ret;
}

void search_diff(int array[], int len, int* pa, int* pb)
{
    if( (array != NULL) && (pa != NULL) && (pb != NULL) )
    {
        int r = 0;
        int flag = 0;
        
        for(int i=0; i<len; i++)
        {
            r = r ^ array[i];
        }
        
        flag = 1 << first_one_bit(r);
        
        *pa = 0;
        *pb = 0;
        
        for(int i=0; i<len; i++)
        {
            if( array[i] & flag )
            {
                *pa = *pa ^ array[i];
            }
            else
            {
                *pb = *pb ^ array[i];
            }
        }
    }
}

int main()
{
	int a = 0;
	int b = 0;
	int array[] = {3, 4, 5, 5, 3, 4, 1, 6, 6, 7, 2, 8, 7, 8};

    search_diff(array, sizeof(array) / sizeof(*array), &a, &b);
	
	cout<<a<<" "<<b<<endl;
}

