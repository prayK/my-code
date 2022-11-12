#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s)
{
    if (s == NULL)
    {
        return 0;
    }
    int Len = strlen(s);
    int Max = 0;              //记录最长的长度max
    int Left = 0, Right = 0;  //滑动窗口的左边界和右边界
    int dict[128] = {0};      //和前面的排序一样，搞个类似于哈希表的东西，通过数组记录其出现的相应次数；

    for(; Right<Len; Right++)
    {
        int index = s[Right];   //得到对应字符的下标

        /*若为真，例如"abc"，对应hash为：a：0，b：1，c：2；如果start小于index，说明字符s[i]在之前重复出现过。*/
        if(dict[index] > Left)
        {
            Left = dict[index];//更改左边界的位置
        }

        //将s[Right]存进HashMap
        dict[index] = Right+1;  //注意：到只有一个字符时长度为1，所以这里右边界要加1
        if(Max < Right-Left+1)
        {
            Max = Right-Left+1; //更新最大值
        }
    }
    return Max;
}

int main()
{
    char str[100] = "abcabcbb";
    int Maxlen = lengthOfLongestSubstring(str);

    printf("%d\n", Maxlen);

    return 0;
}
