#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename U>
auto add(T x, U y) -> decltype(x + y)
{
  return x + y;
}

int main()
{
  auto x = 1.4;
  auto y = 2;

  cout << add(x, y) << endl;

  return 0;
}