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

class Solution
{
public:
    //三指针法
    ListNode *reverseList(ListNode *head)
    {
        if ((head == nullptr) || (head->next == nullptr))
            return head;

        ListNode *beg = nullptr;
        ListNode *mid = head;
        ListNode *end = nullptr; //保存 cur 的下一个节点

        while (mid)
        {
            end = mid->next; //保存一下 cur 的下一个节点，因为接下来要改变cur->next

            //交换逻辑
            mid->next = beg;
            beg = mid;
            mid = end;
        }
        return beg;
    }
    //递归法
    ListNode *reverseList(ListNode *head)
    {
        if ((head == nullptr) || (head->next == nullptr))
            return head;

        ListNode *last = reverseList(head->next); // 递归调用，翻转第二个节点开始往后的链表
        head->next->next = head;                  // 翻转头节点与第二个节点的指向
        head->next = nullptr;                     // 此时的 head 节点为尾节点，next 需要指向 NULL

        return last;
    }
};