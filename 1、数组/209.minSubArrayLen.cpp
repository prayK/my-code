class Solution
{
public:
    //暴力
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX; //最后的结果
        int sum = 0;            //子序列的数值之和
        int SubLength = 0;      //子序列的长度

        for (int i = 0; i < nums.size(); ++i) //设置子序列的起点的为 i
        {
            sum = 0;
            for (int j = i; j < nums.size(); ++j) //设置子序列的终点是 j
            {
                sum += nums[j];
                if (sum >= target) //一旦发现子序列和超过target,更新result
                {
                    SubLength = j - i + 1; //取子序列的长度
                    result = (SubLength < result) ? SubLength : result;
                    break; //一旦找到了符合条件的最短子序列，就结束当前循环(结束以当前 i 为起点的循环，从下一个点开始继续下一轮)
                }
            }
        }
        //如果 result 没有被赋值的话，那就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
    //滑动窗口
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX; //最后的结果
        int sum = 0;            //滑动窗口的数值之和
        int SubLength = 0;      //滑动窗口的长度
        int i = 0;              //滑动窗口起始位置

        for (int j = 0; j < nums.size(); ++j) //设置子序列的起点的为 i
        {
            sum += nums[j];
            while (sum >= target) //一旦发现子序列和超过target,更新result
            {
                SubLength = j - i + 1; //取子序列的长度
                result = (SubLength < result) ? SubLength : result;
                sum -= nums[i++]; //这里体现出滑动窗口的精髓之处，不断更新 i (子序列的起始位置)
            }
        }
        //如果 result 没有被赋值的话，那就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};