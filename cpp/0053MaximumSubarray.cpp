#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

// 53.最大子序和
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:

// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

// 进阶:

// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/maximum-subarray
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //auto dp = make_unique<int[]>(nums.size());
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int ret = dp[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};

class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int prev = nums[0];
        int ret = prev;
        for (int i = 1; i < nums.size(); ++i)
        {
            prev = max(prev + nums[i], nums[i]);
            ret = max(ret, prev);
        }

        return ret;
    }
};

int main()
{
    vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution slv;
    cout << slv.maxSubArray(vec) << endl;
    Solution2 slv2;
    cout << slv2.maxSubArray(vec) << endl;
    return 0;
}