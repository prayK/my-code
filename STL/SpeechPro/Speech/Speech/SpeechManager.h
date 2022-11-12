#pragma once

#ifndef _SPEECHMANAGER_H_
#define _SPEECHMANAGER_H_



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Speaker.h"

using namespace std;

//管理系统类 
class SpeechManager
{
public:
	vector<int> v1;//保存第一轮比赛选手编号容器
	vector<int> v2;//保存第一轮晋级选手编号容器
	vector<int> victory;//胜出前三名选手编号容器
	map<int, Speaker>m_Speaker;//存放编号以及对应具体选手容器
	int m_Index;//存放比赛的轮数
	bool fileIsEmpty;
	map<int, vector<string>>m_Record;
public:
	SpeechManager();

	void Init();//初始化
	void ShowMenu();//显示菜单
	void ExitSystem();//退出系统
	void CreateSpeaker();//创建选手
	void SpeechDraw();//抽签
	void StartSpeech();//开始比赛
	void SpeechContest();//比赛
	void ShowScore();//显示得分
	void SaveRecord();//保存分数
	void LoadRecord();//读取往届记录
	void ShowRecord();//查看记录
	void ClearRecord();//清空记录

	~SpeechManager();

};



#endif