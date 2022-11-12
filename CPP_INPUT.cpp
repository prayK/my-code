#include <bits/stdc++.h>
using namespace std;

int main()
{
/*
//Input string Solution 1,do not support space
//输入一个字符串
    string Input;
	cin >> Input;
    cout << Input[3] << endl;
	cout << Input << endl;
*/

/*
//Input string Solution 2,support space and the space will be ignore
//输入字符，插进字符串
	int n;
	cin >> n;

	char i;
	string Input;

	while(n-- && cin >> i)
	{
		Input += i;
	}

    cout << Input[3] << endl;
	cout << Input << endl;
*/

/*
//Input number Solution 1,do not support space
    vector<int> Input;
	int a;

	while(cin >> a)
	{
		//cin >> Input;
		if(cin.get() == '\n')
		break;
		Input.push_back(a);
	}
	
    cout << Input[3] << endl;
*/

/*
//Input number Solution 2,support space and the space will be ignore
	int n;
	cin >> n;

	int i;
	vector<int> Input;

	while(n-- && cin >> i)
	{
		Input.push_back(i);
	}

    cout << Input[3] << endl;
*/

    return 0;
}