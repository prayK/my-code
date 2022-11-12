#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findSingle(char *str)
{
  int i, j;
  int len = strlen(str);
  for (i = 0; i < len; i++)
  {
    for (j = i + 1; j < len; j++)
    {
      if (str[i] == str[j])
      {
        break;
      }
      if (j == len - 1)
      {
        printf("%c", str[i]);
        return;
      }
    }
  }
}

int main()
{
  char str[] = "abaccdeff";
  findSingle(str);
  return 0;
}
