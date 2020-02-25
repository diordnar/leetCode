#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <regex>
#include <sstream>

using namespace std;

// 9.判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 示例 1:

// 输入: 121
// 输出: true

// 示例 2:

// 输入: -121
// 输出: false
// 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

// 示例 3:

// 输入: 10
// 输出: false
// 解释: 从右向左读, 为 01 。因此它不是一个回文数。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/palindrome-number
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        int tmp = x;
        long rev = 0;
        while (x != 0)
        {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        int irev = static_cast<int>(rev);
        bool ret = false;
        if (tmp == irev)
        {
            ret = true;
        }
        return ret;
    }
};

class Solution2
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        string str = to_string(x);

        string revStr = str;
        reverse(revStr.begin(), revStr.end());
        return str == revStr ? true : false;
    }
};

class Solution3
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        string str;
        stringstream ss;
        ss << x;
        ss >> str;
        string srev = str;
        reverse(srev.begin(), srev.end());
        return str == srev ? true : false;
    }
};

int main()
{
    Solution slv;
    int i1 = 121;
    int i2 = -121;
    int i3 = 123;
    cout << boolalpha << slv.isPalindrome(i1) << endl;
    cout << boolalpha << slv.isPalindrome(i2) << endl;
    cout << boolalpha << slv.isPalindrome(i3) << endl;
    cout << "**************************************" << endl;
    Solution2 slv2;
    cout << boolalpha << slv2.isPalindrome(i1) << endl;
    cout << boolalpha << slv2.isPalindrome(i2) << endl;
    cout << boolalpha << slv2.isPalindrome(i3) << endl;
    cout << "**************************************" << endl;
    Solution2 slv3;
    cout << boolalpha << slv3.isPalindrome(i1) << endl;
    cout << boolalpha << slv3.isPalindrome(i2) << endl;
    cout << boolalpha << slv3.isPalindrome(i3) << endl;
    return 0;
}