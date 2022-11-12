   #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <ctime>

using namespace std;

//选手类
class Person
{
public:
    string p_name;
    int p_score;
};

//创建Person对象并放入到容器中
void CreatePerson(vector<Person> &v)
{
    string NameSeed = "ABCDE";

    for (int i = 0; i < 5; i++)
    {
        Person p;
        p.p_name = "选手";
        p.p_name += NameSeed[i];
        p.p_score = 0;

        //将人放进vector容器
        v.push_back(p);
    }
}

//将评委打的分数放入到deque容器中,再排序，再删除最低分和最高分，再求平均
void SetScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60; //(0 ~ 40) + 60
            d.push_back(score);
        }
        /*
        cout << "选手：" << it->p_name << "打分：" << endl;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            cout << *dit << " ";
        }
        cout << endl;
*/
        //排序
        sort(d.begin(), d.end());
        //去除最低分和最高分
        d.pop_back();
        d.pop_front();

        //取平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }
        int average = sum / d.size();

        //赋值
        it->p_score = average;
    }
}

void ShowScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->p_name << "平均分：" << it->p_score;
        cout << endl;
    }
}

int main(void)
{
    //随机数种子
    srand((unsigned int)time(NULL));
    vector<Person> v; //存放选手的vector容器
    CreatePerson(v);
    /*
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).p_name << ":" << (*it).p_score << endl;
    }
*/
    SetScore(v);
    ShowScore(v);

    return 0;
}