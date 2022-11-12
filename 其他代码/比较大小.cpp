#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int min(int a, int b)
{
    int d = a - b;
    int flag = ((unsigned int)d) >> 31;
    int array[] = {b, a};
    
    return array[flag];
}

int main(int argc, char *argv[])
{
    cout<< min(1, 2) <<endl;
    cout<< min(2, 1) <<endl;
    cout<< min(2, 10000)<<endl;
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
