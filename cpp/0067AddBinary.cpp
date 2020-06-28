// 67. 二进制求和
// 给你两个二进制字符串，返回它们的和（用二进制表示）。
// 输入为 非空 字符串且只包含数字 1 和 0。
// 示例 1:
// 输入: a = "11", b = "1"
// 输出: "100"
// 示例 2:
// 输入: a = "1010", b = "1011"
// 输出: "10101"

// 提示：
//     每个字符串仅由字符 '0' 或 '1' 组成。
//     1 <= a.length, b.length <= 10^4
//     字符串如果不是 "0" ，就都不含前导零。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/add-binary
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int len1 = a.length(), len2 = b.length(), carry = 0;
        stack<int> stk;
        string res;
        int i = len1 - 1, j = len2 - 1;

        for (; i >= 0 && j >= 0; --i, --j)
        {
            int sum = a[i] - '0' + b[j] - '0' + carry;
            int digit = sum % 2;
            carry = sum / 2;
            stk.push(digit);
        }
        while (i >= 0)
        {
            int sum = a[i] - '0' + carry;
            int digit = sum % 2;
            carry = sum / 2;
            stk.push(digit);
            --i;
        }
        while (j >= 0)
        {
            int sum = b[j] - '0' + carry;
            int digit = sum % 2;
            carry = sum / 2;
            stk.push(digit);
            --j;
        }
        if (carry)
        {
            stk.push(carry);
        }
        while (!stk.empty())
        {
            res += (stk.top() + '0');
            stk.pop();
        }
        return res;
    }
};

class Solution2
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size());
        string res;
        int carry = 0;

        for (int i = 0; i < n; ++i)
        {
            carry += i < a.size() ? (a[i] == '1') : 0;
            carry += i < b.size() ? (b[i] == '1') : 0;
            res.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if (carry)
        {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}