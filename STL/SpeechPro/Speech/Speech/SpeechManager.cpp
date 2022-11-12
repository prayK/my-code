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
	//��ʼ������������
	this->Init();
	//����¼���������
	this->m_Record.clear();
	//����12��ѡ��
	this->CreateSpeaker();
	//���������¼
	this->LoadRecord();
}

void SpeechManager::Init()//��ʼ��
{
	//��ʼ������������
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
}

void SpeechManager::ShowMenu()
{
	cout << "***********************************************" << endl;
	cout << "************** ��ӭ�μ��ݽ����� ***************" << endl;
	cout << "*************** 1.��ʼ�ݽ����� ****************" << endl;
	cout << "*************** 2.�鿴�����¼ ****************" << endl;
	cout << "*************** 3.��ձ�����¼ ****************" << endl;
	cout << "*************** 4.�˳��������� ****************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}

void SpeechManager::ExitSystem()
{
	cout << "�Ѿ��˳�ϵͳ����ӭ�´�ʹ�ã�" << endl;
	system("pause"); 
	exit(0);
}

void SpeechManager::CreateSpeaker()
{
	string NameSeed = "ABCDEFGHIJKL";
	for (unsigned int i = 0; i < NameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += NameSeed[i];

		Speaker sp;
		sp.m_name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		//����ѡ�ֱ�ţ������뵽v1������
		this->v1.push_back(i + 10001);

		//ѡ�ֱ���Լ���Ӧѡ�֣����뵽map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::SpeechDraw()//��ǩ
{
	cout << "�� <" << this->m_Index << "> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "--------------------------" << endl;
	cout << "��ǩ���ݽ�˳������:" << endl;

	if (this->m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << endl;
		}
	}
	else
	{
		//�ڶ��ֱ���
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

void SpeechManager::SpeechContest()//����
{
	cout << "----------�� <" << this->m_Index << "> �ֱ�����ʽ��ʼ----------" << endl;

	//׼��һ����ʱ���������С��ɼ�
	multimap<double, int, greater<double>> groupScore;//�Ӵ�С�����У���multimap����������ظ�
	int num = 0;//��¼��Ա�ĸ�����6����һ��

	vector<int>v_Src;//����ѡ������
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //600-1000 / 10.f
			d.push_back(score);//�ѷ�������queue
		}

		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());//����(����)
		d.pop_front();//ȥ����߷֣�
		d.pop_back();//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);//�ܷ֣���ʼ�ۼ�ֵΪ0
		double avg = sum / (double)d.size();//ȡƽ����

		//��ƽ���ַ��뵽map�����У�map�������ڴ����Ա��Ϣ
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;

		//��������ݷ��뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��

		//ÿ������ȡ��ǰ����,����ʱ��������
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���:" << it->second << " ����" << this->m_Speaker[it->second].m_name
					<< " �ɼ�:" << this->m_Speaker[it->second].m_score[this->m_Index - 1] <<endl;
			}
			int count = 0;
			//ȡ��ǰ������������һ��������
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
			groupScore.clear();//С���������
			cout << endl;
		}
	}

	cout << "------------�� <" << this->m_Index << "> �ֱ�������!------------" << endl;
	system("pause");
}

void SpeechManager::ShowScore()//��ʾ�÷�
{
	cout << "------------�� <" << this->m_Index << "> �ֽ���ѡ����Ϣ����:------------" << endl;

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
		cout << "���:" << *it << " ����" << this->m_Speaker[*it].m_name
			<< " �ɼ�:" << this->m_Speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");  
	system("cls");
	this->ShowMenu();//����ʾһ�²˵�
}

void SpeechManager::SaveRecord()//�������
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�

	//��ÿ��ѡ������д�뵽�ļ���
	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;

	//�����ļ���Ϊ�յ�״̬
	this->fileIsEmpty = false;
}

void SpeechManager::LoadRecord()//��ȡ��¼
{
	ifstream ifs("speech.csv", ios::in);//���ļ�
	//�ж��Ƿ�򿪳ɹ�
	if (!(ifs.is_open()))
	{
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl; 
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ�յ����
	this->fileIsEmpty = false;
	ifs.putback(ch);//�������ȡ�ĵ����ַ��Ż���

	string data;
	int index;//�ڼ���

	while (ifs >> data)
	{
		vector<string>v;//Ϊ�˴��6��string���ַ�������һ�ڶ�����
		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);//�Ҷ���
			if (pos == -1)
			{
				//û���ҵ������
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

void SpeechManager::ShowRecord()//�鿴��¼
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ����߼�¼Ϊ�գ�" << endl;
	}
	for (unsigned int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "��"
			<< "�ھ����:" << this->m_Record[i][0] << "�÷�" << this->m_Record[i][1] << " "
			<< "�Ǿ����:" << this->m_Record[i][2] << "�÷�" << this->m_Record[i][3] << " "
			<< "�������:" << this->m_Record[i][4] << "�÷�" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}

void SpeechManager::StartSpeech()//��ʼ����
{
	//��һ�ֿ�ʼ����
	//1.��ǩ
	this->SpeechDraw();
	//2.����
	this->SpeechContest();
	//3.��ʾ�������
	this->ShowScore();

	//�ڶ��ֱ�����ʼ
	this->m_Index++;
	//1.��ǩ
	this->SpeechDraw();
	//2.����
	this->SpeechContest();
	//3.��ʾ���ս��
	this->ShowScore();

	//���������ļ���
	SaveRecord();

	//���ñ�������ʼ������
	this->Init();
	//����12��ѡ��
	this->CreateSpeaker();
	//���������¼
	this->LoadRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::ClearRecord()//��ռ�¼
{
	cout << "�Ƿ�����������ݣ�" << endl; 
	cout << "1����" << endl;
	cout << "2����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��ʼ������������
		this->Init();
		//����¼���������
		this->m_Record.clear();
		//����12��ѡ��
		this->CreateSpeaker();
		//���������¼
		this->LoadRecord();

		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}