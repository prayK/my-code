#include <bits/stdc++.h>
using namespace std;

int main ()
{
    char str[] ="a,b,c,d,e";
    const char * split1 = ",;";
    char * p;
    p = strtok (str, split1);

    while(p!=NULL) 
    {
        printf ("%s\n", p);
        p = strtok(NULL,split1);
    }
    //getchar();

    return 0;
}