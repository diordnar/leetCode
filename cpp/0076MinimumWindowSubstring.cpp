#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
// 76. 最小覆盖子串
// 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

// 示例：
// 输入: S = "ADOBECODEBANC", T = "ABC"
// 输出: "BANC"

// 说明：
//     如果 S 中不存这样的子串，则返回空字符串 ""。
//     如果 S 中存在这样的子串，我们保证它是唯一的答案。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-window-substring
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int minLen = INT_MAX;
        int start = 0;
        int left = 0, right = 0;
        int match = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> toFind;

        for (auto c : t)
        {
            ++toFind[c];
        }

        while (right < s.length())
        {
            char c1 = s[right];
            if (toFind.count(c1))
            {
                ++window[c1];
                if (window[c1] == toFind[c1])
                {
                    ++match;
                }
            }
            ++right;

            while (match == toFind.size())
            {
                if (right - left < minLen) // right在前面已经递增过，字符串长度变为right - left
                {
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if (toFind.count(c2))
                {
                    --window[c2];
                    if (toFind[c2] > window[c2])
                    {
                        --match;
                    }
                }
                ++left;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

class Solution2 // LeetCode-cn 运行时间较短的
{
public:
    string minWindow(string s, string t)
    {

        // r不断前进，直到最后
        //     直到满足T
        //         记录结果
        //         然后缩小尾巴，l++，再判断是否满足T

        //问题是怎么判断满足了T

        int count[256] = {0};
        for (auto c : t)
            count[c]++;

        string res;
        int minLength = s.length();
        int len = 0;

        for (int l = 0, r = 0; r < s.length(); r++)
        {
            count[s[r]]--;
            if (count[s[r]] >= 0)
                len++;
            while (len == t.length())
            {
                if (minLength >= r - l + 1)
                {
                    minLength = r - l + 1;
                    res = s.substr(l, r - l + 1);
                }
                count[s[l]]++;
                if (count[s[l]] >= 1)
                    len--;
                l++;
            }
        }
        return res;
    }
};

class Solution3
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> map;
        for (auto c : t)
            map[c]++;
        int left = 0, cnt = 0, maxlen = s.size() + 1, start = left;
        for (int i = 0; i < s.size(); ++i)
        {
            if (--map[s[i]] >= 0)
                ++cnt;
            while (cnt == t.size())
            {
                if (maxlen > i - left + 1)
                {
                    maxlen = i - left + 1;
                    start = left;
                }
                if (++map[s[left]] > 0)
                    cnt--;
                left++;
            }
        }
        return maxlen == s.size() + 1 ? "" : s.substr(start, maxlen);
    }
};

class Solution33 // Solution3
{
public:
    string minWindow(string s, string t)
    {
        int left = 0, right = 0, start = left, cnt = 0, minLen = INT_MAX;
        unordered_map<char, int> map;
        for (auto c : t)
        {
            ++map[c];
        }

        for (; right < s.length(); ++right)
        {
            if (--map[s[right]] >= 0)
            {
                ++cnt;
            }

            while (cnt == t.length())
            {
                if (minLen > right - left + 1)
                {
                    minLen = right - left + 1;
                    start = left;
                }
                if (++map[s[left]] > 0)
                {
                    --cnt;
                }
                ++left;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main()
{
    string S = "ADOBECODEBANC", T = "ABC";
    Solution33 slv;
    cout << slv.minWindow(S, T) << endl;
    return 0;
}