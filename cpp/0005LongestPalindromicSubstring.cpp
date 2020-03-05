#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    // https://leetcode-cn.com/problems/longest-palindromic-substring/solution/cyu-yan-zui-chang-hui-wen-zi-chuan-by-penn-10/
    string longestPalindrome(string s)
    {
        int start = 0;
        int maxLen = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            int left = i - 1, right = i + 1;
            while (left >= 0 && right < len && s[left] == s[right])
            {
                --left;
                ++right;
            }
            if (right - left - 1 > maxLen)
            {
                maxLen = right - left - 1; // maxLen = right - left + 1 - 2
                start = left + 1;
            }
        }

        for (int i = 0; i < len; ++i)
        {
            int left = i, right = i + 1;
            while (left >= 0 && right < len && s[left] == s[right])
            {
                --left;
                ++right;
            }
            if (right - left - 1 > maxLen) // maxLen = right - left + 1 - 2
            {
                maxLen = right - left - 1;
                start = left + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};

class Solution2
{
public:
    // https://leetcode-cn.com/problems/longest-palindromic-substring/solution/cyu-yan-zui-chang-hui-wen-zi-chuan-by-penn-10/
    string longestPalindrome(string s)
    {
        int start = 0;
        int maxLen = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            help(s, len, i - 1, i + 1, start, maxLen); // 奇数回文
        }

        for (int i = 0; i < len; ++i)
        {
            help(s, len, i, i + 1, start, maxLen); //偶数回文
        }
        return s.substr(start, maxLen);
    }

private:
    void help(string s, int length, int left, int right, int &start, int &maxLen)
    {
        while (left >= 0 && right < length && s[left] == s[right])
        {
            --left;
            ++right;
        }
        if (right - left - 1 > maxLen) // maxLen = right - left + 1 - 2
        {
            maxLen = right - left - 1;
            start = left + 1;
        }
    }
};

class Solution3
{
public:
    string longestPalindrome(string s)
    {
        auto len = s.length();
        int start = 0;
        int maxLen = 1;
        if (len < 2)
            return s;

        vector<vector<int>> dp(len, vector<int>(len, 0));

        // NOT supported by C++ Standard;Supported by g++ as extended feature;Not supported by MSVC
        // int dp[len][len] = {0};
        for (int j = 1; j < len; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]) == 1)
                {
                    dp[i][j] = 1;
                    if (j - i + 1 > maxLen)
                    {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main()
{
    string str = "admmccbabccadd";
    Solution slv;
    cout << slv.longestPalindrome(str) << endl;
    Solution2 slv2;
    cout << slv2.longestPalindrome(str) << endl;
    Solution3 slv3;
    cout << slv3.longestPalindrome(str) << endl;
    return 0;
}