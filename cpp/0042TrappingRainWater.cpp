#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// 42. 接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
// 感谢 Marcos 贡献此图。

// 示例:
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/trapping-rain-water
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// Two Pointers
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        int left = 0;
        int right = n - 1;
        int res = 0;
        int l_max = height[0];
        int r_max = height[n - 1];
        while (left <= right)
        {
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);
            if (l_max < r_max)
            {
                res += l_max - height[left];
                ++left;
            }
            else
            {
                res += r_max - height[right];
                --right;
            }
        }
        return res;
    }
};

// Memo
class Solution2
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        int res = 0;
        vector<int> l_max(n), r_max(n);
        l_max[0] = height[0];
        r_max[n - 1] = height[n - 1];
        for (int i = 1; i < n - 1; ++i)
        {
            l_max[i] = max(height[i], l_max[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i)
        {
            r_max[i] = max(height[i], r_max[i + 1]);
        }

        for (int i = 1; i < n - 1; ++i)
        {
            res += min(l_max[i], r_max[i]) - height[i];
        }
        return res;
    }
};

// Brute force
class Solution3
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        int res = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            int l_max = 0;
            int r_max = 0;
            // 右边最大值
            for (int j = i; j < n; ++j)
            {
                r_max = max(r_max, height[j]);
            }
            // 左边最大值
            for (int j = i; j >= 0; --j)
            {
                l_max = max(l_max, height[j]);
            }
            res += min(l_max, r_max) - height[i];
        }
        return res;
    }
};

int main()
{
    vector<int> heights{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution3 slv3;
    cout << slv3.trap(heights) << endl;

    Solution2 slv2;
    cout << slv2.trap(heights) << endl;

    Solution slv;
    cout << slv.trap(heights) << endl;
    return 0;
}