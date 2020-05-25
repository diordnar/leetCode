#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 18. 四数之和
// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
// 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
// 注意：

// 答案中不可以包含重复的四元组。
// 示例：
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
// 满足要求的四元组集合为：
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/4sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        vector<vector<int>> res;
        if (len < 4)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= len - 4; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) // 去重
            {
                continue;
            }
            for (int j = i + 1; j <= len - 3; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) // 去重
                {
                    continue;
                }
                int left = j + 1;
                int right = len - 1;
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            --right;
                        }
                        ++left;
                        --right;
                    }
                    else if (sum > target)
                    {
                        --right;
                    }
                    else if (sum < target)
                    {
                        ++left;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> vec = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution slv;
    vector<vector<int>> res = slv.fourSum(vec, target);
    for (auto v : res)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}