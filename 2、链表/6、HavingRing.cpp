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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *fast = head;
        ListNode *slow = head;

        while ((fast != nullptr) && (fast->next != nullptr))
        {
            slow = slow->next;
            fast = fast->next->next; //快指针多走一步

            if (slow == fast) // 快慢指针相遇，此时从 head 和相遇点，同时查找(每次都走一步)直至相遇，此时相遇点就是入口
            {
                ListNode *index1 = fast; //slow也行
                ListNode *index2 = head;

                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; //返回环的入口
            }
        }
        return nullptr;
    }
};