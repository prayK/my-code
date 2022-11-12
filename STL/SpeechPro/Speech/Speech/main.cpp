#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include "SpeechManager.h"
#include "Speaker.h" 

using namespace std;

int main()
{
	//随机数种子
	srand((unsigned int) time(NULL));
	SpeechManager sm; 
	int Choice = 0;//用来存储用户的选项  

	while (1)
	{
		sm.ShowMenu();//菜单显示

		cout << "请输入您的选择: ";
		cin >> Choice;

		switch (Choice)
		{
			case 1: sm.StartSpeech(); break; //开始比赛
			case 2: sm.ShowRecord(); break; //查看记录
			case 3: sm.ClearRecord(); break; //清空记录
			case 4: sm.ExitSystem(); break; //退出系统
			default: system("cls"); break; //清屏
		}
	}
	
	system("pause");

	return 0; 
}