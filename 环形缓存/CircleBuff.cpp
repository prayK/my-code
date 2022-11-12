#include <iostream>
using namespace std;

class RingBuffer2
{
private:
  char *buffer;
  int head;
  int tail;
  int size;
  int capacity;

public:
  RingBuffer2(int cp) : capacity(cp)
  {
    buffer = new char[cp];
    head = 0;
    tail = 0;
    size = 0;
  }
  ~RingBuffer2()
  {
    delete[] buffer;
    buffer = nullptr;
  }
  bool full()
  {
    return capacity == size;
  }
  bool empty()
  {
    return size == 0;
  }
  int get_size()
  {
    return size;
  }
  int write(char *src, int len)
  {
    int cur_len = 0;
    for (int i = 0; i < len; i++)
    {
      if (full())
        break;
      buffer[tail] = src[i];
      tail = (tail + 1) % capacity;
      size++;
      cur_len++;
    }
    return cur_len;
  }
  int read(char *src, int len)
  {
    int cur_len = min(len, size);
    for (int i = 0; i < cur_len; i++)
    {
      src[i] = buffer[head];
      head = (head + 1) % capacity;
      size--;
    }
    return cur_len;
  }
  char &operator[](int index)
  {
    return buffer[(head + index) % capacity];
  }
};