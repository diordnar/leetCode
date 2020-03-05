#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
// 516. 最长回文子序列
// 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

// 示例 1:
// 输入:
// "bbbab"
// 输出:
// 4
// 一个可能的最长回文子序列为 "bbbb"。

// 示例 2:
// 输入:
// "cbbd"
// 输出:
// 2
// 一个可能的最长回文子序列为 "bb"。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int sz = s.length();
        if (sz <= 1)
            return sz;
        vector<vector<int>> dp(sz, vector<int>(sz, 0));

        // Base case
        for (int i = 0; i < sz; ++i)
        {
            dp[i][i] = 1;
        }
        //     0   1   2   3   4  j
        //   +---+---+---+---+---+
        // 0 | 1 |   |   |   | ? |
        //   +---+---+---+---+---+
        // 1 | 0 | 1 |   |   |   |
        //   +---+---+---+---+---+
        // 2 | 0 | 0 | 1 |   |   |
        //   +---+---+---+---+---+
        // 3 | 0 | 0 | 0 | 1 |   |
        //   +---+---+---+---+---+
        // 4 | 0 | 0 | 0 | 0 | 1 |
        //   +---+---+---+---+---+
        // i
        for (int i = sz - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < sz; ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};
class Solution2
{
public:
    int longestPalindromeSubseq(string s)
    {
        auto sz = s.length();
        if (sz <= 1)
            return sz;
        //vector<vector<int>> dp(sz, vector<int>(sz, 0));

        int **dp = new int *[sz];
        for (int i = 0; i < sz; ++i)
        {
            dp[i] = new int[sz];
        }

        // Base case
        for (int i = 0; i < sz; ++i)
        {
            dp[i][i] = 1;
        }
        //     0   1   2   3   4  j
        //   +---+---+---+---+---+
        // 0 | 1 |   |   |   | ? |
        //   +---+---+---+---+---+
        // 1 | 0 | 1 |   |   |   |
        //   +---+---+---+---+---+
        // 2 | 0 | 0 | 1 |   |   |
        //   +---+---+---+---+---+
        // 3 | 0 | 0 | 0 | 1 |   |
        //   +---+---+---+---+---+
        // 4 | 0 | 0 | 0 | 0 | 1 |
        //   +---+---+---+---+---+
        // i
        for (int i = sz - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < sz; ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        int ret = dp[0][sz - 1];
        for (int i = 0; i < sz; ++i)
        {
            delete[] dp[i];
        }

        delete[] dp;
        return ret;
    }
};
int main()
{
    string s1 = "bbbab"; // output 4  "bbbb"
    string s2 = "cbbd";  // output 2  "bb"
    cout << Solution().longestPalindromeSubseq(s1) << endl;
    cout << Solution().longestPalindromeSubseq(s2) << endl;
    return 0;
}