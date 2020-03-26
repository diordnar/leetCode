// 56. 合并区间
// 给出一个区间的集合，请合并所有重叠的区间。

// 示例 1:
// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

// 示例 2:
// 输入: [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/merge-intervals
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.empty())
        {
            return res;
        }
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            auto curr = intervals[i];
            auto &last = res.back();
            if (curr[0] <= last[1])
            {
                last[1] = max(curr[1], last[1]);
            }
            else
            {
                res.push_back(curr);
            }
        }

        return res;
    }
};

int main()
{
    // 输入: [[1,3],[2,6],[8,10],[15,18]]
    // 输出: [[1,6],[8,10],[15,18]]
    vector<vector<int>> vec{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution slv;
    auto ret = slv.merge(vec);
    return 0;
}