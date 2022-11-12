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