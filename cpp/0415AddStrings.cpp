#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// 415. 字符串相加
// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

// 注意：

//     num1 和num2 的长度都小于 5100.
//     num1 和num2 都只包含数字 0-9.
//     num1 和num2 都不包含任何前导零。
//     你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int len1 = num1.length();
        int len2 = num2.length();
        int maxLen = max(len1, len2);
        string s1;
        string s2;
        if (len1 >= len2)
        {
            s1 = num1;
            s2 = num2;
        }
        else
        {
            s1 = num2;
            s2 = num1;
        }

        int minLen = min(len1, len2);
        vector<int> ans(maxLen + 1);
        for (int i = maxLen - 1, j = minLen - 1; i >= 0; --i, --j)
        {
            int add = s1[i] - '0' + (j >= 0 ? s2[j] - '0' : 0);
            int sum = ans[i + 1] + add;
            ans[i + 1] = sum % 10;
            ans[i] += sum / 10;
        }

        int pos = (ans[0] == 0) ? 1 : 0;
        string str;
        while (pos < ans.size())
        {
            str.push_back(ans[pos] + '0');
            ++pos;
        }
        return str;
    }
};

class Solution2
{
public:
    string addStrings(string num1, string num2)
    {
        if (num2.length() > num1.length())
        {
            return _addStrings(num2, num1);
        }
        return _addStrings(num1, num2);
    }

private:
    string _addStrings(string s1, string s2) // assume s1.length > s2.length
    {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<int> ans(len1 + 1, 0);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int i = 0;
        for (; i < len2; ++i)
        {
            int add = s1[i] - '0' + (s2[i] - '0');
            int sum = ans[i] + add;
            ans[i] = sum % 10;
            ans[i + 1] += sum / 10;
        }
        for (; i < len1; ++i)
        {
            int sum = ans[i] + (s1[i] - '0');
            ans[i] = sum % 10;
            ans[i + 1] += sum / 10;
        }
        string str;
        int pos = (ans[len1] == 0) ? len1 - 1 : len1;
        while (pos >= 0)
        {
            str.push_back(ans[pos] + '0');
            --pos;
        }
        return str;
    }
};

int main()
{
    Solution2 slv;
    string s1 = "99";
    string s2 = "99";
    cout << slv.addStrings(s1, s2) << endl;
    cout << slv.addStrings("0", "0") << endl;
    cout << slv.addStrings("10", "0") << endl;
    cout << slv.addStrings("9", "99") << endl;
    cout << slv.addStrings("999", "1") << endl;
    return 0;
}