#pragma once

#ifndef _SPEECHMANAGER_H_
#define _SPEECHMANAGER_H_



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Speaker.h"

using namespace std;

//����ϵͳ�� 
class SpeechManager
{
public:
	vector<int> v1;//�����һ�ֱ���ѡ�ֱ������
	vector<int> v2;//�����һ�ֽ���ѡ�ֱ������
	vector<int> victory;//ʤ��ǰ����ѡ�ֱ������
	map<int, Speaker>m_Speaker;//��ű���Լ���Ӧ����ѡ������
	int m_Index;//��ű���������
	bool fileIsEmpty;
	map<int, vector<string>>m_Record;
public:
	SpeechManager();

	void Init();//��ʼ��
	void ShowMenu();//��ʾ�˵�
	void ExitSystem();//�˳�ϵͳ
	void CreateSpeaker();//����ѡ��
	void SpeechDraw();//��ǩ
	void StartSpeech();//��ʼ����
	void SpeechContest();//����
	void ShowScore();//��ʾ�÷�
	void SaveRecord();//�������
	void LoadRecord();//��ȡ�����¼
	void ShowRecord();//�鿴��¼
	void ClearRecord();//��ռ�¼

	~SpeechManager();

};



#endif