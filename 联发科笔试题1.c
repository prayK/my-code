#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct ListNode
{
  int value;
  struct ListNode *next;
  struct ListNode *prev;
} List;

List *Create(void)
{
  List *Head = (List *)malloc(sizeof(List));
  Head->next = NULL;
  Head->prev = NULL;

  List *cur = Head;

  printf("Input Number:\r\n");
  do
  {
    List *node = (List *)malloc(sizeof(List));
    scanf("%d", &(node->value));

    node->prev = cur;
    cur->next = node;
    cur = node;

  } while (getchar() != '\n');

  cur->next = NULL;

  return Head;
}

void Insert(List *Head, int index, int value)
{
  List *temp = Head;
  int i = 1;

  while ((temp != NULL) && (i < index - 1))
  {
    temp = temp->next;
    ++i;
  }
  List *node = (List *)malloc(sizeof(List));
  node->value = value;

  node->prev = temp;
  node->next = temp->next;

  temp->next->prev = node;
  temp->next = node;
}

void Delete(List *Head, int index, int *value)
{
  List *temp = Head;
  int i = 1;

  while ((temp != NULL) && (i < index))
  {
    temp = temp->next;
    ++i;
  }
  *value = temp->value;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;

  free(temp);
  temp = NULL;
}

void Sort(List *Head)
{
  List *node1 = Head;
  List *node2 = NULL;

  while (node1 != NULL)
  {
    node2 = node1->next;
    while (node2 != NULL)
    {
      if (node1->value > node2->value)
      {
        int temp = node1->value;
        node1->value = node2->value;
        node2->value = temp;
      }
      node2 = node2->next;
    }
    node1 = node1->next;
  }
}

int main()
{
  List *Head = Create();

  List *NewHead1 = Head->next;
  while (NewHead1 != NULL)
  {
    printf("%d ", NewHead1->value);
    NewHead1 = NewHead1->next;
  }
  printf("\n");

  List *NewHead2 = Head->next;
  Insert(NewHead2, 3, 99);
  while (NewHead2 != NULL)
  {
    printf("%d ", NewHead2->value);
    NewHead2 = NewHead2->next;
  }
  printf("\n");

  List *NewHead3 = Head->next;
  int val;
  Delete(NewHead3, 3, &val);
  while (NewHead3 != NULL)
  {
    printf("%d ", NewHead3->value);
    NewHead3 = NewHead3->next;
  }
  printf(": %d\n", val);

  List *NewHead4 = Head->next;
  Sort(NewHead4);
  while (NewHead4 != NULL)
  {
    printf("%d ", NewHead4->value);
    NewHead4 = NewHead4->next;
  }
  printf("\n");

  return 0;
}
