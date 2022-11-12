#include <cstdlib>
#include <iostream>
#include <string>
#include <list>

using namespace std;

void abstring(string& a, int ai, string& b, int bi, list<int>& l)
{
    if( bi == b.length() )
    {
        for(list<int>::iterator it=l.begin(); it!=l.end(); it++)
        {
            cout<<*it;
        }
        
        cout<<endl;
    }
    else
    {
        for(int i=ai; i<a.length(); i++)
        {
            if( a[i] == b[bi] )
            {
                l.push_back(i);
                
                abstring(a, i + 1, b, bi + 1, l);
                
                l.pop_back();
            }
        }
    }
}

void output_postion(const char* a, const char* b)
{
    string as = a;
    string bs = b;
    list<int> l;
    
    abstring(as, 0, bs, 0, l);
}

int main(int argc, char *argv[])
{
    output_postion("abdbcc", "abc");
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
