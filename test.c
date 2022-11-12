#include <iostream>

using namespace std;

class Solution
{
public:
  int index = 0;
  int len = 0;

  int MaxSubArr(vector<int> &Arr)
  {
    int res = INT_MIN;
    int sum = 0;

    for (int i = 0; i < Arr.size(); ++i)
    {
      sum += Arr[i];
      index = i;
      if (sum > res)
      {
        res = sum;
        len++;
      }
      if (sum <= 0)
      {
        sum = 0;
        len = 0;
      }
    }
    return res;
  }
};

int main(void)
{
  class Solution MySolution;
  vector<int> Arr = {-3, 1, 3, -1, 2, -4, 2};

  int Res = MySolution.MaxSubArr(Arr);
  vector<int> ResArr;

  for (int i = MySolution.index; i < MySolution.len; i++)
  {
    ResArr.push_back(Arr[i]);
    cout << ResArr[i] << " ";
  }

  cout << endl
       << Res << endl;

  return 0
}