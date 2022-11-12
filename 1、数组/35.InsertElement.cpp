class Solution
{
public:
    //暴力
    /*
    int searchInsert(vector<int>& nums, int target) 
    {
        if(nums.empty() == true)
            return 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] >= target)
                return i;
        }
        return nums.size();
    }
*/
    //二分
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.empty() == true)
            return 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return right + 1;
    }
};