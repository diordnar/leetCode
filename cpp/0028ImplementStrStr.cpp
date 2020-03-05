#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 28. 实现 strStr()
// 实现 strStr() 函数。
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle
// 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
// 示例 1:
// 输入: haystack = "hello", needle = "ll"
// 输出: 2

// 示例 2:
// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1
// 说明:
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf()
// 定义相符。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/implement-strstr
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class KMP
{
public:
    KMP(string pattern) : pat(pattern), dp(pat.length(), vector<int>(256, 0))
    {
        int M = pat.length();
        dp[0][pat[0]] = 1;

        int X = 0;
        for (int j = 1; j < M; ++j)
        {
            for (int c = 0; c < 256; ++c)
            {
                dp[j][c] = dp[X][c];
            }
            dp[j][pat[j]] = j + 1;
            X = dp[X][pat[j]];
        }

        // for (int j = 1; j < M; ++j)
        // {
        //     for (int c = 0; c < 256; ++c)
        //     {
        //         if (pat[j] == c)
        //         {
        //             dp[j][c] = j + 1;
        //         }
        //         else
        //         {
        //             dp[j][c] = dp[X][c];
        //         }
        //     }
        //     X = dp[X][pat[j]];
        // }
    }
    KMP() = delete;

    int search(string s)
    {
        int M = pat.length();
        int N = s.length();
        int j = 0;
        for (int i = 0; i < N; ++i)
        {
            j = dp[j][s[i]];
            if (j == M)
            {
                return i - M + 1;
            }
        }
        return -1;
    }

private:
    string pat;
    vector<vector<int>> dp;
};

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        KMP kmp(needle);
        return kmp.search(haystack);
    }
};

class Solution2
{
public:
    int strStr(string haystack, string needle)
    {
        if (0 == needle.size())
        {
            return 0;
        }

        int index = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack.size() - i < needle.size())
            {
                return -1;
            }

            for (int j = 0; j < needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    index = 0;
                    break;
                }
                else
                {
                    index++;
                }
            }

            if (index == needle.size())
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    KMP kmp("abc");
    cout << kmp.search("fffffababcrrrrrr") << endl;

    Solution slv;
    cout << slv.strStr("fffffababcrrrrrr", "abc") << endl;

    Solution2 slv2;
    cout << slv2.strStr("fffffababcrrrrrr", "abc") << endl;
    return 0;
}
