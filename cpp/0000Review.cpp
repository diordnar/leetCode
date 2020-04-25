#include <unordered_map>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <climits> // INT_MAX

using namespace std;

/******************************* 双指针 Start *****************************************/
// Sliding Window START
class C76 // 最小覆盖子串
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

    string minWindow2(string s, string t)
    {
        int left = 0, right = 0, start = left, minLen = INT_MAX, match = 0;
        unordered_map<char, int> needs;
        unordered_map<char, int> window;
        for (auto c : t)
        {
            ++needs[c];
        }

        for (; right < s.length(); ++right)
        {
            char c1 = s[right];
            if (needs.count(c1))
            {
                ++window[c1];
                if (window[c1] == needs[c1])
                {
                    ++match;
                }
            }

            while (match == needs.size())
            {
                if (minLen > right - left + 1)
                {
                    minLen = right - left + 1;
                    start = left;
                }
                char c2 = s[left];
                if (needs.count(c2))
                {
                    --window[c2];
                    if (window[c2] < needs[c2])
                    {
                        --match;
                    }
                }
                ++left;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }

    string minWindow3(string s, string t)
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

    string minWindow4(string s, string t)
    {
        int left = 0, right = 0, start = left, minLen = INT_MAX;
        int match = 0;
        unordered_map<char, int> needs;
        unordered_map<char, int> window;

        for (auto c : t)
        {
            ++needs[c];
        }

        for (; right < s.length(); ++right)
        {
            char c1 = s[right];
            if (needs.count(c1))
            {
                ++window[c1];
                if (window[c1] == needs[c1])
                {
                    ++match;
                }
            }

            while (match == needs.size())
            {
                char c2 = s[left];
                if (minLen > right - left + 1)
                {
                    minLen = right - left + 1;
                    start = left;
                }
                if (needs.count(c2))
                {
                    --window[c2];
                    if (window[c2] < needs[c2])
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

// 438. 找到字符串中所有字母异位词
class C438
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int left = 0, right = 0, match = 0;
        unordered_map<char, int> needs;
        unordered_map<char, int> window;
        vector<int> res;
        for (auto c : p)
        {
            ++needs[c];
        }
        for (; right < s.length(); ++right)
        {
            char c1 = s[right];
            if (needs.count(c1))
            {
                ++window[c1];
                if (needs[c1] == window[c1])
                {
                    ++match;
                }
            }

            while (match == needs.size())
            {
                char c2 = s[left];
                if (right - left + 1 == p.length())
                {
                    res.push_back(left);
                }
                if (needs.count(c2))
                {
                    --window[c2];
                    if (window[c2] < needs[c2])
                    {
                        --match;
                    }
                }
                ++left;
            }
        }

        return res;
    }

    vector<int> findAnagrams2(string s, string p)
    {
        int left = 0, right = 0, cnt = 0;
        vector<int> res;
        unordered_map<char, int> umap;
        for (auto c : p)
        {
            ++umap[c];
        }

        for (; right < s.length(); ++right)
        {
            if (--umap[s[right]] >= 0)
            {
                ++cnt;
            }

            while (cnt == p.length())
            {
                if (right - left + 1 == p.length())
                {
                    res.push_back(left);
                }
                if (++umap[s[left]] > 0)
                {
                    --cnt;
                }
                ++left;
            }
        }
        return res;
    }
};
// 无重复字符的最长子串
class C3
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, maxLen = INT_MIN;
        unordered_map<char, int> window;
        for (; right < s.length(); ++right)
        {
            char c1 = s[right];
            ++window[c1];

            while (window[c1] > 1)
            {
                char c2 = s[left];
                --window[c2];
                ++left;
            }
            if (maxLen < right - left + 1)
            {
                maxLen = right - left + 1;
            }
        }
        return maxLen;
    }

    // int lengthOfLongestSubstring2(string s)
    // {
    // }
};
// Sliding Window END
/******************************* 双指针 End   *****************************************/

int main()
{
    /******************************* 双指针 Start *****************************************/
    // Sliding Window START
    {
        string S = "ADOBECODEBANC", T = "ABC";
        C76 c76;
        cout << c76.minWindow2(S, T) << endl;
        cout << c76.minWindow4(S, T) << endl;
    }
    {
        string s = "cbaebabacd", p = "abc";
        C438 c438;
        vector<int> ret = c438.findAnagrams2(s, p);
        for (auto i : ret)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    {
        string s = "abcdfgabcbb";
        C3 c3;
        cout << c3.lengthOfLongestSubstring(s) << endl;
    }

    // Sliding Window END
    /******************************* 双指针 End   *****************************************/
    return 0;
}