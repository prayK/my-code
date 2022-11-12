#include <stdio.h>
// index 表示求数列中第 index 个位置上的数的值
int fibonacci(int index)
{
    // 设置结束递归的限制条件
    if (index == 1 || index == 2)
    {
        return 1;
    }
    // F(index) = F(index-1) + F(index-2)
    return fibonacci(index - 1) + fibonacci(index - 2);
}
int main()
{
    int i;
    // 输出前 10 个数
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}