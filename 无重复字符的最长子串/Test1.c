#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s)
{
    if (s == NULL) return 0;
    int max = 0;              //记录最长的长度max
    int left = 0, right = 0;  //滑动窗口的左边界和右边界
    int dict[128] = {0};      //和前面的排序一样，搞个类似于哈希表的东西，通过数组记录其出现的相应次数；
    int index;

    for(; s[right] != '\0' ; right++)
    {
        index = s[right];   //得到对应字符的下标

        /*若为真，例如"abc"，对应hash为：a：0，b：1，c：2；如果start小于index，说明字符s[i]在之前重复出现过。*/
        if(dict[index] > left)
        {
            left = dict[index];
        }

        dict[index] = right+1;  //注意：到只有一个字符时长度为1，所以这里右边界要加1
        if(max < right-left+1)
        {
            max = right-left+1; //更新最大值
        }
    }
    return max;
}

main()
{
    char str[100] = "abcabcbb";
    int Maxlen = lengthOfLongestSubstring(str);

    printf("%d\n", Maxlen);

    return 0;
}
