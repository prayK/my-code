#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int value) : value(value), next(nullptr) {}
    ListNode(int value, ListNode* next) : value(value), next(next) {} 
    
    ListNode* CreateListNode()
    {
        ListNode* Head = new ListNode;
        Head->next = nullptr;
        ListNode* cur = Head;

        cout << "Input Your Number:";

        do
        {
            ListNode* node = new ListNode;
            cin >> node->value;
        
            cur->next = node;
            cur = node;
        } while (getchar() != '\n');
        
        cur->next = nullptr;
        
        return Head;
    }   
};

class MyList
{
public:
    /* 反转链表 */
    ListNode* Reverse(ListNode* Head)
    {
        if((Head == nullptr) || (Head->next == nullptr))
        {
            return Head;
        }
        ListNode* beg = nullptr;
        ListNode* mid = Head;
        ListNode* end = nullptr;//保存 cur 的下一个节点

        while(mid)
        {
            end = mid->next;//保存一下 cur 的下一个节点，因为接下来要改变cur->next

            //交换逻辑
            mid->next = beg;
            beg = mid;
            mid = end;
        }
        return beg;
    }

    /* 删除存 value 的节点 */
    ListNode* DeleteNode(ListNode* Head, int value)
    {
        if(Head == nullptr)
        {
            return Head;
        }
        ListNode* NewHead = new ListNode(0);//设置一个虚拟节点
        NewHead->next = head;
        ListNode* cur = NewHead;

        while(cur->next != nullptr)
        {
            if(cur->next->value == value)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = NewHead->next;
        delete NewHead;

        return Head;
    }

    /* 删除倒数第 n 个节点 */
    ListNode* RemoveNthFromEnd(ListNode *head, int n)
    {
        if((head == nullptr) || (n < 0))
        {
            return head;
        }
        ListNode* NewHead = new ListNode(0);
        NewHead->next = head;
        ListNode* slow = NewHead;
        ListNode* fast = NewHead;

        while(n-- && fast != nullptr)
        {
            fast = fast->next;
        }
        fast = fast->next;//fast需要再提前走一步，因为需要让 slow 指向带删除节点的上一个节点

        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        head = NewHead->next;
        delete NewHead;

        return head;
    }

    /* 链表节点之间两两交换 */
    ListNode* SwapPairs(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *NewHead = new ListNode(0);//设置一个虚拟头结点
        NewHead->next = head;//将虚拟头结点指向 head，这样方便后面做删除操作
        ListNode* cur = NewHead;

        while((cur->next != nullptr) && (cur->next->next != nullptr))
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

    /* 链表是否有环 */
    ListNode* HavingRing(ListNode* Head)
    {
        if((Head == nullptr) || (Head->next == nullptr))
        {
            return Head;
        }
        ListNode *fast = Head;
        ListNode *slow = Head;

        while((fast != nullptr) && (fast->next != nullptr))
        {
            slow = slow->next;
            fast = fast->next->next;//快指针多走一步

            if(slow == fast)// 快慢指针相遇，此时从 head 和相遇点，同时查找(每次都走一步)直至相遇，此时相遇点就是入口
            {
                ListNode* index1 = fast;
                ListNode* index2 = Head;

                while(index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }

    /* 判断链表是否相交 */
    ListNode* Intersection(ListNode* headA, ListNode* headB)
    {
        if((headA == nullptr) || (headB == nullptr))
        {
            return nullptr;
        }
        ListNode* curLong = headA;
        ListNode* curShort = headB;

        int lenA = 0;
        int lenB = 0;

        while(curLong != nullptr)// 求链表A的长度
        {
            ++lenA;
            curLong = curLong->next;
        }
        while(curShort != nullptr)// 求链表B的长度
        {
            ++lenB;
            curShort = curShort->next;
        }

        if(lenA > lenB)// 让curLong为最长链表的头
        {
            curLong = headA;
            curShort = headB;
        }
        else //必须要加上这个分支，为了让两个游标指回头结点
        {
            curLong = headB;
            curShort = headA;
        }

        int len = (lenA - lenB) ? (lenA - lenB) : (lenB - lenA);
        while(len--)// 让curA和curB在同一起点上（末尾位置对齐）
        {
            curLong = curLong->next;
        }

        while(curLong != nullptr)// 遍历curA 和 curB，遇到相同则直接返回
        {
            if(curLong == curShort)
            {
                return curLong;
            }
            curLong = curLong->next;
            curShort = curShort->next;
        }

        return nullptr;
    }
};