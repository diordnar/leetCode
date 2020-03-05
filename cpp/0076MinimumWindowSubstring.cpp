#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

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

int main()
{
    string S = "ADOBECODEBANC", T = "ABC";
    Solution slv;
    cout << slv.minWindow(S, T) << endl;
    return 0;
}