#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> array = {1, 3, 5};

  for (auto it = array.begin(); it != array.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;

  auto a = 1.3;
  auto b = 2;
  decltype(a + b) z = 3.6;

  cout << z << endl;

  return 0;
}