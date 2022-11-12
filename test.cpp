#include <iostream>
#include <vector>
using namespace std;

void findAndKill(list_node_t *List, int k, int m)
{
  list_node_t *p = List;

  list_node_t *Front = List;
  while (Front->next != List)
  {
    Front = Front->next;
  }
  //找到第k个人
  while (p->value != k)
  {
    Front = p;
    p = p->next;
  }
  //从编号为k的人开始，只有符合p->next==p时，说明链表中除了p结点，所有编号都出列了，
  while (p->next != p)
  {
    for (int i = 1; i < m; i++)
    {
      Front = p;
      p = p->next;
    }
    Front->next = p->next; //将报m的人挪走
    printf("出列人的编号为:%d\n", p->value);
  }
  free(p);
}
