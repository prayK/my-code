#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>

using namespace std;

class Worker
{
public:
    string w_name;
    int w_salary;
};

void CreateWorker(vector<Worker> &v)
{
    string NameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.w_name = "员工";
        worker.w_name += NameSeed[i];
        worker.w_salary = rand() % 10000 + 10000; //10000 ~ 19999

        //将员工放入到容器中
        v.push_back(worker);
    }
}

void SetGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //产生随机部门编号
        int deptID = rand() % 3; //0 1 2
        //将员工插入到分组中
        //m.insert(make_pair(deptID, *it));
        m.insert(pair<int, Worker>(deptID, *it));
    }
}
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

void ShowWorkerGroup(multimap<int, Worker> &m)
{
    //0:A B C    1: B C D   2:E F G
    cout << "策划部门信息:" << endl;

    //利用一个迭代器接受策划部门第一个数据的位置
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    //统计这个部门有多少人
    int count = m.count(CEHUA);

    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.w_name << "工资" << pos->second.w_salary;
    }

    cout << endl
         << "_________________" << endl;
    cout << "美术部门信息:" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.w_name << "工资" << pos->second.w_salary;
    }

    cout << endl
         << "_________________" << endl;
    cout << "研发部门信息:" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.w_name << "工资" << pos->second.w_salary;
    }
}

int main(void)
{
    srand((unsigned int)time(NULL)); //利用系统时间做一个真实的随机

    //创建员工
    vector<Worker> v;
    CreateWorker(v);

    //员工分组，放进multimap中
    multimap<int, Worker> mWorker;
    SetGroup(v, mWorker);

    //分组显示员工
    ShowWorkerGroup(mWorker);

    return 0;
}