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

//直接使用原来的链表来进行移除节点的操作
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *NewHead = new ListNode(0); //设置一个虚拟头结点
        NewHead->next = head;                //将虚拟头结点指向 head，这样方便后面做删除操作
        ListNode *cur = NewHead;

        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmp1 = cur->next;             //记录临时节点
            ListNode *tmp2 = cur->next->next->next; //记录临时节点

            cur->next = cur->next->next;  //将第一个节点与第三个节点连接起来
            cur->next->next = tmp1;       //将第三个节点与第二个节点连接起来
            cur->next->next->next = tmp2; //将第二个节点与第四个节点连接起来

            cur = cur->next->next;
        }
        head = NewHead->next;
        delete NewHead;

        return head;
    }
};