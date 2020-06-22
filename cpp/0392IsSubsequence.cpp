// 392. 判断子序列
// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
// 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），
// 而 s 是个短字符串（长度 <=100）。
// 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
// （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

// 示例 1:
// s = "abc", t = "ahbgdc"
// 返回 true.

// 示例 2:
// s = "axc", t = "ahbgdc"
// 返回 false.

// 后续挑战 :
// 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。
// 在这种情况下，你会怎样改变代码？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/is-subsequence
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int slen = s.size();
        int tlen = t.size();
        int i = 0;
        for (int j = 0; j < slen; ++j)
        {
            while (i < tlen && t[i] != s[j])
            {
                ++i;
            }
            ++i;
        }
        return i <= tlen ? true : false;
    }
};

class Solution2
{
public:
    bool isSubsequence(string s, string t)
    {
        int slen = s.size();
        int tlen = t.size();
        int i = 0, j = 0;
        while (i < slen && j < tlen)
        {
            if (s[i] == t[j])
            {
                ++i;
                ++j;
            }
            else
            {
                ++j;
            }
        }
        return i == slen;
    }
};

// 后续挑战 :
// 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。
// 在这种情况下，你会怎样改变代码？
class Solution2
{
public:
    bool isSubsequence(string s, string t)
    {
        t = ' ' + t; // 开头加一个空字符，不然第一个字符的下一个字符的位置为-1
        int slen = s.size();
        int tlen = t.size();
        vector<vector<int>> dp(tlen, vector<int>(26, 0));
        for (char c = 0; c < 26; ++c)
        {
            int nextPos = -1;                   // 表示接下来再不会出现该字符
            for (int i = tlen - 1; i >= 0; --i) // 为了获得下一个字符的位置，要从后往前
            {
                dp[i][c] = nextPos;
                if (t[i] == c + 'a')
                {
                    nextPos = i;
                }
            }
        }

        int index = 0;
        for (auto c : s)
        {
            index = dp[index][c - 'a'];
            if (index == -1)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
