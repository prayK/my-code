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
    //删除链表中倒数第 n 个节点
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if ((head == nullptr) || (n < 0))
            return head;

        ListNode *NewHead = new ListNide(0);
        NewHead->next = head;
        ListNode *slow = NewHead;
        ListNode *fast = NewHead;

        while (n-- && fast != nullptr)
            fast = fast->next;
        fast = fast->next; //fast需要再提前走一步，因为需要让 slow 指向带删除节点的上一个节点

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        head = NewHead->next;
        delete NewHead;

        return head;
    }
};