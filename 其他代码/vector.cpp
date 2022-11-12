
#include <bits/stdc++.h>
using namespace std;

void *RemoveSameChar(char input[], int len)
{
  int hashmap[128] = {0};
  char output[len] = {0};
  int index = 0;

  for (int i = 0; i < len; ++i)
  {
    hashmap[input[i]]++;
  }
  for (int i = 0; i < 128; ++i)
  {
    if (hashmap[input[i]] == 1)
    {
      output[index++] = i + '0';
    }
  }
  return output;
}

/*
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    vector<vector<string>> res;

    vector<string> res1;
    string input1;

    while(cin >> input1)
    {
        if("BREAK" == input1) break;
        else res1.push_back(input1);
    }

    vector<string> res2;
    string input2;

    while(cin >> input2)
    {
        if("BREAK" == input2) break;
        else res2.push_back(input2);
    }

    res.push_back(res1);
    res.push_back(res2);

    for(vector<vector<string>>::iterator it = res.begin(); it != res.end(); ++it)
    {
        for(vector<string>::iterator it1 = it->begin(); it1 != it->end(); ++it1)
        {
            cout << *it1 << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < res1.size(); ++i)
    {
        for(int j = 0; j < res2.size(); ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    for(auto &row : res)
    {
        for(auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
  vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}};
  vector<vector<int>>::iterator it1 = v.begin();
  reverse((*it1).begin(), (*it1).end());
  ++it1;
  reverse((*it1).begin(), (*it1).end());
  reverse(v.begin(), v.end());

  /*
      for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it)
      {
          for (vector<int>::iterator it1 = (*it).begin(); it1 != (*it).end(); ++it1)
          {
              cout << *it1 << " ";
          }
      }
  */

  for (auto it = v.begin(); it != v.end(); ++it)
  {
    for (auto it1 = (*it).begin(); it1 != (*it).end(); ++it1)
    {
      cout << *it1 << " ";
    }
  }
  return 0;
}