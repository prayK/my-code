#include <bits/stdc++.h>
using namespace std;

#define Length 10

class CircleQueue
{
public:
  int front;
  int rear;
  int Data[Length];

  CircleQueue()
  {
    this->front = 0;
    this->rear = 0;
    for (int i = 0; i < Length; ++i)
    {
      this->Data[i] = 0;
    }
  }
  int getQueueLength()
  {
    return (rear - front + Length) % Length;
  }
  ~CircleQueue() {}
};

void EnQueue(CircleQueue &Queue, int data)
{
  if ((Queue.rear + 1) % Length == Queue.front)
  {
    cout << "Full Queue" << endl;
  }
  Queue.Data[Queue.rear] = data;
  Queue.rear = (Queue.rear + 1) % Length;
}

void Dequeue(CircleQueue &Queue, int &data)
{
  if (Queue.front == Queue.rear)
  {
    cout << "Empty Queue" << endl;
  }
  data = Queue.Data[Queue.front];
  Queue.front = (Queue.front + 1) % Length;
}

int main()
{
  CircleQueue Queue;
  for (int i = 0; i < Length; i++)
  {
    EnQueue(Queue, i);
    cout << i << " ";
  }
  cout << endl;

  return 0;
}