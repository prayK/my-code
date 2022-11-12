#include <iostream>
#include <functional>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include "SpeechManager.h"
#include "Speaker.h"

using namespace std;

SpeechManager::SpeechManager()
{
	//初始化容器和属性
	this->Init();
	//将记录的容器清空
	this->m_Record.clear();
	//创建12名选手
	this->CreateSpeaker();
	//记载往届记录
	this->LoadRecord();
}

void SpeechManager::Init()//初始化
{
	//初始化容器和属性
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
}

void SpeechManager::ShowMenu()
{
	cout << "***********************************************" << endl;
	cout << "************** 欢迎参加演讲比赛 ***************" << endl;
	cout << "*************** 1.开始演讲比赛 ****************" << endl;
	cout << "*************** 2.查看往届记录 ****************" << endl;
	cout << "*************** 3.清空比赛记录 ****************" << endl;
	cout << "*************** 4.退出比赛程序 ****************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}

void SpeechManager::ExitSystem()
{
	cout << "已经退出系统，欢迎下次使用！" << endl;
	system("pause"); 
	exit(0);
}

void SpeechManager::CreateSpeaker()
{
	string NameSeed = "ABCDEFGHIJKL";
	for (unsigned int i = 0; i < NameSeed.size(); i++)
	{
		string name = "选手";
		name += NameSeed[i];

		Speaker sp;
		sp.m_name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		//创建选手编号，并放入到v1容器中
		this->v1.push_back(i + 10001);

		//选手编号以及对应选手，放入到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::SpeechDraw()//抽签
{
	cout << "第 <" << this->m_Index << "> 轮比赛选手正在抽签" << endl;
	cout << "--------------------------" << endl;
	cout << "抽签后演讲顺序如下:" << endl;

	if (this->m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << endl;
		}
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << endl;
		}
	}
	cout << "--------------------------" << endl;
	system("pause");

	cout << endl;
}

void SpeechManager::SpeechContest()//比赛
{
	cout << "----------第 <" << this->m_Index << "> 轮比赛正式开始----------" << endl;

	//准备一个临时容器来存放小组成绩
	multimap<double, int, greater<double>> groupScore;//从大到小来排列，用multimap，允许分数重复
	int num = 0;//记录人员的个数，6个人一组

	vector<int>v_Src;//比赛选手容器
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //600-1000 / 10.f
			d.push_back(score);//把分数插入queue
		}

		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());//排序(降序)
		d.pop_front();//去除最高分；
		d.pop_back();//去除最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);//总分，起始累加值为0
		double avg = sum / (double)d.size();//取平均分

		//将平均分放入到map容器中，map容器用于存放人员信息
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;

		//将打分数据放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));//key是得分，value是具体选手编号

		//每六个人取出前三名,用临时容器保存
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号:" << it->second << " 姓名" << this->m_Speaker[it->second].m_name
					<< " 成绩:" << this->m_Speaker[it->second].m_score[this->m_Index - 1] <<endl;
			}
			int count = 0;
			//取走前三名，放在下一轮容器中
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); (it != groupScore.end() && count < 3); it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					victory.push_back((*it).second);
				}
			}
			groupScore.clear();//小组容器清空
			cout << endl;
		}
	}

	cout << "------------第 <" << this->m_Index << "> 轮比赛结束!------------" << endl;
	system("pause");
}

void SpeechManager::ShowScore()//显示得分
{
	cout << "------------第 <" << this->m_Index << "> 轮晋级选手信息如下:------------" << endl;

	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = victory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号:" << *it << " 姓名" << this->m_Speaker[*it].m_name
			<< " 成绩:" << this->m_Speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");  
	system("cls");
	this->ShowMenu();//再显示一下菜单
}

void SpeechManager::SaveRecord()//保存分数
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件

	//将每个选手数据写入到文件中
	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();
	cout << "记录已经保存" << endl;

	//更改文件不为空的状态
	this->fileIsEmpty = false;
}

void SpeechManager::LoadRecord()//读取记录
{
	ifstream ifs("speech.csv", ios::in);//读文件
	//判断是否打开成功
	if (!(ifs.is_open()))
	{
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl; 
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空的情况
	this->fileIsEmpty = false;
	ifs.putback(ch);//将上面读取的单个字符放回来

	string data;
	int index;//第几届

	while (ifs >> data)
	{
		vector<string>v;//为了存放6个string的字符串，第一第二第三
		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);//找逗号
			if (pos == -1)
			{
				//没有找到的情况
				break;
			}
			string temp = data.substr(start, pos-start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
/*
	for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << it->first << it->second[0] << it->second[1] << endl;
	}
*/
}

void SpeechManager::ShowRecord()//查看记录
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在，或者记录为空！" << endl;
	}
	for (unsigned int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届"
			<< "冠军编号:" << this->m_Record[i][0] << "得分" << this->m_Record[i][1] << " "
			<< "亚军编号:" << this->m_Record[i][2] << "得分" << this->m_Record[i][3] << " "
			<< "季军编号:" << this->m_Record[i][4] << "得分" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}

void SpeechManager::StartSpeech()//开始比赛
{
	//第一轮开始比赛
	//1.抽签
	this->SpeechDraw();
	//2.比赛
	this->SpeechContest();
	//3.显示晋级结果
	this->ShowScore();

	//第二轮比赛开始
	this->m_Index++;
	//1.抽签
	this->SpeechDraw();
	//2.比赛
	this->SpeechContest();
	//3.显示最终结果
	this->ShowScore();

	//保存结果到文件中
	SaveRecord();

	//重置比赛，初始化属性
	this->Init();
	//创建12名选手
	this->CreateSpeaker();
	//记载往届记录
	this->LoadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::ClearRecord()//清空记录
{
	cout << "是否清空所有数据？" << endl; 
	cout << "1、是" << endl;
	cout << "2、否" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//确认清空
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化容器和属性
		this->Init();
		//将记录的容器清空
		this->m_Record.clear();
		//创建12名选手
		this->CreateSpeaker();
		//记载往届记录
		this->LoadRecord();

		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}