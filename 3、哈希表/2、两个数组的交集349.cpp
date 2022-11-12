#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> ResultSet; //存放结果
        unordered_set<int> NumSet(nums1.begin(), nums1.end());

        for (int &num : nums2)
        {
            if (NumSet.find(num) != NumSet.end())
            {
                ResultSet.insert(num);
            }
        }
        return vector<int>(ResultSet.begin(), ResultSet.end());
    }
};