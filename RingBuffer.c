#include <iostream>
#include <vector>

using namespace std;

#define RING_BUFFER_SIZE 12 /*环形队列元素个数*/

/*环形队列*/
class RingBuffer
{
private:
  int head;
  int rear;
  int data[RING_BUFFER_SIZE];

public:
  RingBuffer() : head(0), rear(0) {}

  /* 添加 */
  void Encode(int value)
  {
    cout << "head=" << head << " rear=" << rear << " Encode value:" << value << endl;
    data[rear] = value;
    rear = (rear + 1) % RING_BUFFER_SIZE;
  }

  /* 删除 */
  int Decode()
  {
    int value = data[head];
    head = (head + 1) % RING_BUFFER_SIZE;
    return value;
  }

  /* 判断空 */
  bool Empty()
  {
    return (head == rear) ? true : false;
  }

  /* 判断满 */
  bool Full()
  {
    return ((rear + 1) % RING_BUFFER_SIZE == head) ? true : false;
  }

  /* 统计个数 */
  int DataNum()
  {
    return (rear - head + RING_BUFFER_SIZE) % RING_BUFFER_SIZE;
  }
};

int main()
{
  RingBuffer ringBuffer;

  return 0;
}