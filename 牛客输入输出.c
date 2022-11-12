////////知道一行多少数据
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int num;
  string temp;
  vector<string> MyString;
  cin >> num;
  for (int i = 0; i < num; ++i)
  {
    string temp;
    cin >> temp;
    MyString.push_back(temp);
  }
  stable_sort(MyString.begin(), MyString.end());
  for (auto &i : MyString)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}

////////知道一行多少数据，就一行
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int num;
  cin >> num;
  string temp;
  vector<string> MyString;

  while (cin >> temp)
  {
    MyString.push_back(temp);
    if (cin.get() == '\n') //
    {
      stable_sort(MyString.begin(), MyString.end());
    }
  }
  for (auto &i : MyString)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}

/////////不知道一行多少数据，不知道多少行
#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> res;
  int val = 0;
  int sum = 0;

  while (cin >> val)
  {
    sum += val;
    if (cin.get() == '\n')
    {
      res.push_back(sum);
      sum = 0;
    }
  }
  for (auto &i : res)
  {
    cout << i << endl;
  }

  return 0;
}

//总结：一行结束用 if(cin.get() == '\n')判断
//全部数据输入完毕while(cin >> val)就退出了

int main()
{
  int Teacher = 0;
  int Student = 0;
  int Max = 0;

  cin >> Teacher >> Student >> Max;

  vector<vector<string>> TeacherLan;
  vector<string> StudentLan;

  for (int i = 0; i < Teacher; ++i)
  {
    vector<string> vec;
    string temp;
    while (cin >> temp)
    {
      vec.push_back(temp);
      if (cin.get() == '\n')
      {
        TeacherLan.push_back(vec);
        vec.clear();
        break;
      }
    }
  }
  for (int j = 0; j < Student; ++j)
  {
    string temp;
    cin >> temp;
    StudentLan.push_back(temp);
  }

  for (auto &i : TeacherLan)
  {
    for (auto &j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  for (auto &i : StudentLan)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
  string Input;
  cin >> Input;

  vector<string> Output;
  string temp;
  for (auto &i : Input)
  {
    if (i != ';')
    {
      temp += i;
    }
    else
    {
      Output.push_back(temp);
      temp.clear();
      continue;
    }
  }
  for (auto &i : Output)
  {
    cout << i << endl;
  }

  return 0;
}
