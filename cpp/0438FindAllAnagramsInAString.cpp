#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
// 438. 找到字符串中所有字母异位词
// 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

// 说明：

//     字母异位词指字母相同，但排列不同的字符串。
//     不考虑答案输出的顺序。

// 示例 1:

// 输入:
// s: "cbaebabacd" p: "abc"

// 输出:
// [0, 6]

// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

//  示例 2:

// 输入:
// s: "abab" p: "ab"

// 输出:
// [0, 1, 2]

// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ret;
        int left = 0, right = 0;
        int match = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> toFind;

        for (auto c : p)
        {
            ++toFind[c];
        }
        int slen = s.length();
        while (right < slen)
        {
            char c1 = s[right];
            if (toFind.count(c1))
            {
                ++window[c1];
                if (toFind[c1] == window[c1])
                {
                    ++match;
                }
            }
            ++right;
            while (match == toFind.size())
            {
                char c2 = s[left];
                if (right - left == p.length())
                {
                    ret.push_back(left);
                }
                if (toFind.count(c2))
                {
                    --window[c2];
                    if (window[c2] < toFind[c2])
                    {
                        --match;
                    }
                }
                ++left;
            }
        }

        return ret;
    }
};

class Solution2 // LeetCode-cn 运行时间较短的
{
public:
    vector<int> minWindow(string s, string p)
    {

        // r不断前进，直到最后
        //     直到满足T
        //         记录结果
        //         然后缩小尾巴，l++，再判断是否满足T

        //问题是怎么判断满足了T

        vector<int> ret;
        int count[256] = {0};
        for (auto c : p)
            count[c]++;

        int len = 0;

        for (int l = 0, r = 0; r < s.length(); r++)
        {
            count[s[r]]--;
            if (count[s[r]] >= 0)
                len++;
            while (len == p.length())
            {
                if (p.length() == r - l + 1)
                {
                    ret.push_back(l);
                }
                count[s[l]]++;
                if (count[s[l]] >= 1)
                    len--;
                l++;
            }
        }
        return ret;
    }
};

int main()
{
    string s = "cbaebabacd", p = "abc";
    Solution slv;
    vector<int> result1 = slv.findAnagrams(s, p);
    Solution slv2;
    vector<int> result2 = slv2.findAnagrams(s, p);
    // for (auto i : result1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    for (auto i : result2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}