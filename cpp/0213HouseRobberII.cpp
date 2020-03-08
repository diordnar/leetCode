#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// 213. 打家劫舍 II
// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，
// 这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
// 示例 1:
// 输入: [2,3,2]
// 输出: 3
// 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

// 示例 2:
// 输入: [1,2,3,1]
// 输出: 4
// 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//      偷窃到的最高金额 = 1 + 3 = 4 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/house-robber-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]); // 只有两个房间时不算首尾相连
        return max(robRange(nums, 0, len - 2), robRange(nums, 1, len - 1));
    }

private:
    int robRange(vector<int> &nums, int start, int end)
    {
        int dp_i_2 = nums[start];
        int dp_i_1 = max(nums[start], nums[start + 1]);
        int dp_i = dp_i_1; // 只有两个房间时返回两个中的最大
        for (int i = start + 2; i <= end; ++i)
        {
            dp_i = max(dp_i_2 + nums[i], dp_i_1);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }

        return dp_i;
    }
};

class Solution2
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        return max(robRange(nums, 0, len - 2), robRange(nums, 1, len - 1));
    }

private:
    int robRange(vector<int> &nums, int start, int end)
    {
        int dp_i_2 = 0; // 消除长度等于1时的特殊情况处理——不能取nums[1]
        int dp_i_1 = 0;
        int dp_i = 0;
        for (int i = start; i <= end; ++i)
        {
            dp_i = max(dp_i_2 + nums[i], dp_i_1);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }

        return dp_i;
    }
};

int main()
{
    vector<int> vec1{2, 3, 2};    // output 3
    vector<int> vec2{1, 2, 3, 1}; // output 4

    Solution slv;
    cout << slv.rob(vec1) << endl;
    cout << slv.rob(vec2) << endl;
    return 0;
}