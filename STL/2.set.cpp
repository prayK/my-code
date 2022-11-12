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

using namespace std;

class Person
{
public:
    string p_name;
    int p_age;

public:
    Person(string name, int age)
    {
        this->p_age = age;
        this->p_name = name;
    }
};

class Compare
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.p_age < p2.p_age;
    }
};
int main(void)
{
    set<Person, Compare> s;

    Person p1("刘备", 24);
    Person p2("张飞", 22);
    Person p3("关羽", 23);
    Person p4("赵云", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, Compare>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << it->p_name << it->p_age << endl;
    }

    cout << endl;

    return 0;
}