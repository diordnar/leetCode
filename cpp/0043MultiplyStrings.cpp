#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 43.Multiply Strings
// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，
// 它们的乘积也表示为字符串形式。

// 示例 1:
// 输入: num1 = "2", num2 = "3"
// 输出: "6"

// 示例 2:
// 输入: num1 = "123", num2 = "456"
// 输出: "56088"

// 说明：
//     num1 和 num2 的长度小于110。
//     num1 和 num2 只包含数字 0-9。
//     num1 和 num2 均不以零开头，除非是数字 0 本身。
//     不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int m = num1.size();
        int n = num2.size();
        // 两位数相乘最多m + n位，例如：99 * 99 = 9801
        vector<int> res(m + n);
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                int v1 = num1[i] - '0';
                int v2 = num2[j] - '0';
                int mul = v1 * v2;
                int sum = res[i + j + 1] + mul;
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        int i = 0;
        while (i < res.size() && res[i] == 0)
        {
            ++i;
        }
        string str;
        for (; i < res.size(); ++i)
        {
            str.push_back(res[i] + '0');
        }

        return str.size() == 0 ? "0" : str;
    }
};

class Solution2
{
public:
    // 他人的LeetCode解答,执行时间少
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int s1 = num1.size(), s2 = num2.size();

        //int ans[s1 + s2] = {0};
        vector<int> ans(s1 + s2, 0);
        for (int i = 0; i < s1; i++)
        {
            for (int j = 0; j < s2; j++)
            {
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for (int i = 0; i < s1 + s2; i++)
        {
            if (ans[i] > 9)
            {
                int t = ans[i];
                ans[i] = t % 10;
                ans[i + 1] += (t / 10);
            }
        }

        int pos = (ans[s1 + s2 - 1] == 0 ? s1 + s2 - 2 : s1 + s2 - 1);

        string aa = "";
        for (; pos >= 0; --pos)
        {
            aa += (ans[pos] + '0');
        }
        return aa;
    }
};

int main()
{
    Solution2 slv;
    string s1 = "123";
    string s2 = "456";
    cout << slv.multiply(s1, s2) << endl;
    return 0;
}
