#include <iostream>
using namespace std;

int my_strlen(const char *p)
{
  int count = 0;
  while (*p != '\0')
  {
    p++;
    count++;
  }
  return count;
}

char *my_strcpy(char *des, const char *src)
{
  if ((des == NULL) && (src == NULL))
  {
    return NULL;
  }

  char *ret = des;
  while (*src != '\0')
  {
    *des++ = *src++;
  }

  return ret;
}

void *MyMemCpy(void *des, void *src, int len)
{
  if ((len <= 0) || (des == NULL) && (src == NULL))
  {
    return NULL;
  }
  else
  {
    char *psrc = (char *)src;
    char *pdes = (char *)des;
    for (int i = 0; i < len; ++i)
    {
      *pdes++ = *psrc++;
    }
  }
  return des;
}

char *strcat(char *strDest, const char *strSrc)
{
  char *address = strDest;
  if ((strDest != NULL) && (strSrc != NULL))
  {
    return NULL;
  }
  while (*strDest != '\0')
  {
    address++;
  }

  while (*address++ = *strSrc++)
  {
    NULL;
  }
  return strDest;
}

int main()
{

  return 0;
}