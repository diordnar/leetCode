#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <regex>
#include <sstream>
#include <unordered_map>
#include <map>
#include <memory>

using namespace std;
// 70.爬楼梯
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 注意：给定 n 是一个正整数。

// 示例 1：

// 输入： 2
// 输出： 2
// 解释： 有两种方法可以爬到楼顶。
// 1.  1 阶 + 1 阶
// 2.  2 阶

// 示例 2：

// 输入： 3
// 输出： 3
// 解释： 有三种方法可以爬到楼顶。
// 1.  1 阶 + 1 阶 + 1 阶
// 2.  1 阶 + 2 阶
// 3.  2 阶 + 1 阶

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/climbing-stairs
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        //int *dp = new int[n + 1]; // delete [] dp;
        auto dp = make_unique<int[]>(n + 1); // C++14
        //unique_ptr<int[]> dp3(new int[n + 1]);
        //auto dp2 = make_shared<int[]>(n + 1); // C++2a

        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution2
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int first = 1, second = 2, third = 0;

        for (int i = 3; i <= n; ++i)
        {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};

int main()
{
    int steps = 20;
    Solution slv;
    cout << slv.climbStairs(steps) << endl;
    Solution2 slv2;
    cout << slv2.climbStairs(steps) << endl;
    return 0;
}