#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> array = {1, 3, 5};

  for (auto &i : array)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}