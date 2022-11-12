class Solution
{
public:
    //暴力
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] = nums[i] * nums[i];
        }
        stable_sort(nums.begin(), nums.end());
        return nums;
    }
    //双指针
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        int index = nums.size() - 1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            if ((nums[left] * nums[left]) > (nums[right] * nums[right]))
            {
                result[index--] = nums[left] * nums[left];
                left++;
            }
            else
            {
                result[index--] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};