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
  ListNode *removeElements(ListNode *head, int val)
  {
    if (head == nullptr)
      return nullptr;
    while (head != nullptr && head->val == val)
    {
      head = head->next;
    }

    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr)
    {
      if (cur->next->val == val)
      {
        cur->next = cur->next->next;
      }
      else
      {
        cur = cur->next;
      }
    }
    return head;
  }
};

//设置一个虚拟节点再进行移除节点操作(推荐)
class Solution
{
  ListNode *removeElements(ListNode *head, int val)
  {
    if (head == nullptr)
      return nullptr;

    ListNode *NewHead = new ListNode(0); //设置一个虚拟节点
    NewHead->next = head;                //将虚拟节点指向head，这样方便后面做删除操作
    ListNode *cur = NewHead;

    while (cur->next != nullptr)
    {
      if (cur->next->val == val)
        cur->next = cur->next->next;
      else
        cur = cur->next;
    }
    head = NewHead->next;
    delete NewHead;

    return head;
  }
};