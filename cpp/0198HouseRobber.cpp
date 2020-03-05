#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

// 198.打家劫舍
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
// 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，
// 系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

// 示例 1:

// 输入: [1,2,3,1]
// 输出: 4
// 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//      偷窃到的最高金额 = 1 + 3 = 4 。

// 示例 2:

// 输入: [2,7,9,3,1]
// 输出: 12
// 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//      偷窃到的最高金额 = 2 + 9 + 1 = 12 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/house-robber
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
    int rob(vector<int> &nums)
    {
        int sz = nums.size();
        if (sz == 0)
        {
            return 0;
        }
        if (sz == 1)
            return nums[0];
        vector<int> dp(sz);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < sz; ++i)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[sz - 1];
    }
};

class Solution2
{
public:
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
    int rob(vector<int> &nums)
    {
        int sz = nums.size();
        if (sz == 0)
        {
            return 0;
        }
        if (sz == 1)
            return nums[0];
        int prevMax = 0;
        int currMax = 0;

        int dp_i = 0;
        int dp_i_1 = max(nums[0], nums[1]);
        int dp_i_2 = nums[0];
        for (int i = 2; i < sz; ++i)
        {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;

        // prevMax = nums[0];
        // currMax = max(nums[0], nums[1]);
        // for (int i = 2; i < sz; ++i)
        // {
        //     // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        //     int tmp = currMax;
        //     currMax = max(prevMax + nums[i], currMax);
        //     prevMax = tmp;
        // }
        // return currMax;
    }
};

int main()
{
    vector<int> vec1{1, 2, 3, 1};
    vector<int> vec2{2, 7, 9, 3, 1};
    Solution slv;
    cout << slv.rob(vec1) << endl;
    cout << slv.rob(vec2) << endl;
    Solution2 slv2;
    cout << slv2.rob(vec1) << endl;
    cout << slv2.rob(vec2) << endl;
    return 0;
}