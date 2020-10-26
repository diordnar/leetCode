#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

// 90. 子集 II
// 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
// 说明：解集不能包含重复的子集。
// 示例:
// 输入: [1,2,2]
// 输出:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/subsets-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> track;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, track);
        return res;
    }

    void backtrack(vector<int> &nums, int start, vector<int> &track)
    {
        res.push_back(track);
        int n = nums.size();
        for (int i = start; i < n; ++i)
        {
            if (i > start && nums[i] == nums[i - 1]) // 剪枝
            {
                continue;
            }
            track.push_back(nums[i]);      // 选择
            backtrack(nums, i + 1, track); // 递归进入下一层
            track.pop_back();              // 撤销选择
        }
    }
};