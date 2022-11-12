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
	//���������
	srand((unsigned int) time(NULL));
	SpeechManager sm; 
	int Choice = 0;//�����洢�û���ѡ��  

	while (1)
	{
		sm.ShowMenu();//�˵���ʾ

		cout << "����������ѡ��: ";
		cin >> Choice;

		switch (Choice)
		{
			case 1: sm.StartSpeech(); break; //��ʼ����
			case 2: sm.ShowRecord(); break; //�鿴��¼
			case 3: sm.ClearRecord(); break; //��ռ�¼
			case 4: sm.ExitSystem(); break; //�˳�ϵͳ
			default: system("cls"); break; //����
		}
	}
	
	system("pause");

	return 0; 
}