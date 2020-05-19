#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

// 15. 三数之和
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
// 请你找出所有满足条件且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。

// 示例：
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/3sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3)
        {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; ++i)
        {
            if (nums[i] > 0) // 若当前数大于0，则和一定大于0
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) // 去重
            {
                continue;
            }
            int left = i + 1;
            int right = len - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) // 去重
                    {
                        ++left;
                    }
                    while (left < right && nums[right] = nums[right - 1]) // 去重
                    {
                        --right;
                    }
                    ++left;
                    --right;
                }
                else if (sum > 0)
                {
                    --right;
                }
                else if (sum < 0)
                {
                    ++left;
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}