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
  //�ҵ���k����
  while (p->value != k)
  {
    Front = p;
    p = p->next;
  }
  //�ӱ��Ϊk���˿�ʼ��ֻ�з���p->next==pʱ��˵�������г���p��㣬���б�Ŷ������ˣ�
  while (p->next != p)
  {
    for (int i = 1; i < m; i++)
    {
      Front = p;
      p = p->next;
    }
    Front->next = p->next; //����m����Ų��
    printf("�����˵ı��Ϊ:%d\n", p->value);
  }
  free(p);
}
