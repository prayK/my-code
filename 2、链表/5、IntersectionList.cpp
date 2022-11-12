#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//设置一个虚拟节点再进行移除节点操作(推荐)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *curLong = headA;
        ListNode *curShort = headB;
        int lenA = 0;
        int lenB = 0;

        while (curLong != nullptr) // 求链表A的长度
        {
            lenA++;
            curLong = curLong->next;
        }
        while (curShort != nullptr) // 求链表B的长度
        {
            lenB++;
            curShort = curShort->next;
        }
        if (lenB > lenA) // 让curLong为最长链表的头
        {
            curLong = headB;
            curShort = headA;
        }
        else //必须要加上这个分支，为了让两个游标指回头结点
        {
            curLong = headA;
            curShort = headB;
        }
        int len = (lenA > lenB) ? (lenA - lenB) : (lenB - lenA);
        
        while (len--) // 让curA和curB在同一起点上（末尾位置对齐）
        {
            curLong = curLong->next;
        }

        while (curLong != nullptr) // 遍历curA 和 curB，遇到相同则直接返回
        {
            if (curLong == curShort)
            {
                return curLong;
            }
            curLong = curLong->next;
            curShort = curShort->next;
        }
        return nullptr;
    }
};