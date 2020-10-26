#include <vector>

using std::vector;
// 78. 子集
// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
// 说明：解集不能包含重复的子集。
// 示例:
// 输入: nums = [1,2,3]
// 输出:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/subsets
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }

    void backtrack(vector<int> &nums, int start, vector<int> &track)
    {
        res.push_back(track);

        for (int i = start; i < nums.size(); i++)
        {
            track.push_back(nums[i]);      // 做出选择
            backtrack(nums, i + 1, track); // 递归进入下一层，注意i+1，标识下一个选择列表的开始位置，最重要的一步
            track.pop_back();              // 撤销选择
        }
    }
};