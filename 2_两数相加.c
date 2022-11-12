//两数相加

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void CreateLinkList1(struct ListNode* List)
{
    (List)->val = 2;
    (List)->next = NULL;

    struct ListNode* q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    q1->val = 4;
    q1->next = (List)->next;
    (List)->next = q1;

    struct ListNode* q2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    q2->val = 3;
    q2->next = q1->next;
    q1->next = q2;
}

void CreateLinkList2(struct ListNode* List)
{
    (List)->val = 5;
    (List)->next = NULL;

    struct ListNode* q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    q1->val = 6;
    q1->next = (List)->next;
    (List)->next = q1;

    struct ListNode* q2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    q2->val = 4;
    q2->next = q1->next;
    q1->next = q2;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int arraya[100] = {0};
    int arrayb[100] = {0};

    int a = 99;
    int b = 99;

    for(; l1!=NULL; l1=l1->next)
        arraya[a--] = l1->val;//数组从后往前存链表节点值


    for(; l2!=NULL; l2=l2->next)
        arrayb[b--] = l2->val;//数组从后往前存链表节点值

    int flaga = 0;
    long long Totala = 0;//这个总数可能很大
    for(int i=0; i<100; i++)
    {
        if((arraya[i] != 0) || (flaga == 1))//找到数据起始点
        {
            flaga = 1;
            Totala = Totala + arraya[i];
            Totala = Totala * 10;
        }
    }Totala = Totala / 10;
    //printf("Totala = %d\n", Totala);

    int flagb = 0;
    long long Totalb = 0;//这个总数可能很大
    for(int i=0; i<100; i++)
    {
        if((arrayb[i] != 0) || (flagb == 1))//找到数据起始点
        {
            flagb = 1;
            Totalb = Totalb + arrayb[i];
            Totalb = Totalb * 10;
        }
    }Totalb = Totalb / 10;
    //printf("Totalb = %d\n", Totalb);

    long long Total = Totala + Totalb;
    printf("Total = %d\n", Total);

    struct ListNode* List = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* List2 = List;//List2为指向尾部的节点

    List->val = Total % 10;
    //printf("%d ", List->val);
    Total = Total / 10;
    //List->next = NULL;

    for(int i=0; i<100; i++)
    {
        if(Total != 0)
        {
            struct ListNode* Node = (struct ListNode*)malloc(sizeof(struct ListNode));
            Node->val = Total % 10;
            //printf("%d ", Node->val);
            Total = Total / 10;
            List2->next = Node;
            List2 = Node;
        }
    }
    List2->next = NULL;

    return List;
}

int main()
{
    struct ListNode* List1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* List2 = (struct ListNode*)malloc(sizeof(struct ListNode));

    CreateLinkList1(List1);
    CreateLinkList2(List2);

    struct ListNode* List = addTwoNumbers(List1, List2);

    for(; List!=NULL; List=List->next)
    {
        printf("\n%d ", List->val);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
public:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(0), next(next) {}
};

void CreateList(ListNode **head, vector<int> &vec)
{
    (*head) = new ListNode(vec[0]);
    (*head)->next = nullptr;
    ListNode *cur = (*head);

    for(int i = 1; i < vec.size(); ++i)
    {
        ListNode *node = new ListNode(vec[i]);
        cur->next = node;
        cur = node;
    }
    cur->next = nullptr;
}

ListNode *AddTwoNumbers(ListNode *headA, ListNode *headB)
{
    int arraya[100] = {0};
    int arrayb[100] = {0};

    int a = 99;
    int b = 99;

    while(headA != nullptr)
    {
        arraya[a--] = headA->val;
        headA = headA->next;
    }

    while(headB != nullptr)
    {
        arrayb[b--] = headB->val;
        headB = headB->next;
    }

    int flaga = 0;
    long TotalA = 0;
    for(int i = 0; i < 100; i++)
    {
        if((arraya[i] != 0) || (flaga == 1))//找到数据起始点
        {
            flaga = 1;
            TotalA = TotalA * 10 + arraya[i];
        }
    }

    int flagb = 0;
    long TotalB = 0;
    for(int i = 0; i < 100; i++)
    {
        if((arrayb[i] != 0) || (flagb == 1))//找到数据起始点
        {
            flagb = 1;
            TotalB = TotalB * 10 + arrayb[i];
        }
    }

    long Total = TotalA + TotalB;

    ListNode* List = new ListNode(Total % 10);
    Total = Total / 10;

    ListNode* cur = List;
 
    while(Total != 0)
    {
        struct ListNode* node = new ListNode(Total % 10);
        Total = Total / 10;
        cur->next = node;
        cur = node;
    }
    cur->next = nullptr;

    return List;
}

ListNode *AddTwoNumbers(ListNode *headA, ListNode *headB)
{
    struct ListNode* NewHead = NULL;       //头指针
    struct ListNode* cur = NewHead;   //采用尾插法，需要一个指针始终指向尾结点，初始化就是头指针

    int Sum = 0;
    int Num = 0;
    int flag = 0;

    while((headA != NULL) || (headB != NULL) || Num)
    {
        Sum = (headA == NULL ? 0 : headA->val) + (headB == NULL ? 0 : headB->val) + Num;  //任意一个节点为当前两个节点和加上前一位的进位数
        Num = Sum / 10;                     //如果存在进位情况，要得到Num，为后一位运算做准备

        ListNode* ResultNode = new ListNode;//定义转存结果的节点
        ResultNode->val = Sum % 10;         //无论Sum是大于10还是小于10都可以用取模的方式得到结果
        ResultNode->next = NULL;            //指向下一个保存结果的节点

        //指向下一个保存结果的节点
        if(flag == 0)
        {
            flag = 1;               //只进来一次，换个头，(不然在循环里面会无限换头)
            NewHead = ResultNode;   //第一个结果要转存给头结点
            cur = NewHead;
        }
        else
        {
            cur->next = ResultNode;
            cur = ResultNode;
        }
        if(headA != nullptr)
            headA = headA->next;

        if(headB != nullptr)
            headB = headB->next;
    }  
    cur->next = NULL;

    return NewHead;
}

int main()
{
    ListNode *headA;
    ListNode *headB;

    vector<int> vec1 = {2,4,2,8,6,5};
    vector<int> vec2 = {9,2,6,3,1,7};

    CreateList(&headA, vec1);
    CreateList(&headB, vec2);
/*
    while(headA)
    {
        cout << headA->val << " ";
        headA = headA->next;
    }
    cout << endl;
    while(headB)
    {
        cout << headB->val << " ";
        headB = headB->next;
    }
    cout << endl;
*/
    ListNode *head = AddTwoNumbers(headA, headB);
/*
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
*/
    return 0;
}