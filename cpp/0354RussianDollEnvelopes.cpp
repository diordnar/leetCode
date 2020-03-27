#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// 354. 俄罗斯套娃信封问题
// 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比
// 这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
// 请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

// 说明:
// 不允许旋转信封。
// 示例:
// 输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// 输出: 3
// 解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/russian-doll-envelopes
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // 这个解法的关键在于，对于宽度 w 相同的数对，要对其高度 h 进行降序排序。
        // 因为两个宽度相同的信封不能相互包含的，逆序排序保证在 w 相同的数对中最多只选取一个。
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int> &a,
                const vector<int> &b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
        int sz = envelopes.size();
        if (sz <= 0)
        {
            return 0;
        }

        // 排序后变成LIS(最长上升子序列)问题
        vector<int> dp(sz, 1); // 每个元素包含自己

        for (int i = 0; i < sz; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < sz; ++i)
        {
            res = max(res, dp[i]);
        }
        return res;
    }
};
class Solution2
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // 这个解法的关键在于，对于宽度 w 相同的数对，要对其高度 h 进行降序排序。
        // 因为两个宽度相同的信封不能相互包含的，逆序排序保证在 w 相同的数对中最多只选取一个。
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int> &a,
                const vector<int> &b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
        int sz = envelopes.size();
        if (sz <= 1)
        {
            return sz;
        }

        // 排序后变成LIS(最长上升子序列)问题
        vector<int> tails;
        tails.push_back(envelopes[0][1]);

        int end = 0; // tails结尾的索引
        for (int i = 1; i < sz; ++i)
        {
            if (envelopes[i][1] > tails[end])
            {
                tails.push_back(envelopes[i][1]);
                ++end;
            }
            else
            {
                int left = 0;
                int right = end;
                while (left < right)
                {
                    int mid = (left + right) / 2;
                    if (tails[mid] < envelopes[i][1])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid;
                    }
                }
                tails[left] = envelopes[i][1];
            }
        }
        return end + 1;
    }
};
int main()
{
    vector<vector<int>> vec{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    vector<vector<int>> vec2{{1, 3}, {3, 5}, {6, 7}, {6, 8}, {8, 4}, {9, 5}};
    Solution slv;
    cout << slv.maxEnvelopes(vec) << endl;
    cout << slv.maxEnvelopes(vec2) << endl;
    Solution2 slv2;
    cout << slv2.maxEnvelopes(vec) << endl;
    cout << slv2.maxEnvelopes(vec2) << endl;
    return 0;
}