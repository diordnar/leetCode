#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// C++11 m%n求余，符号与m相同，刚开始对符号做了单独处理
// 第一次未考虑溢出情况，提交代码运行时溢出
class Solution
{
public:
    int reverse(int x)
    {
        int ret = 0;
        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                return 0;
            }
            if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && digit < INT_MIN % 10))
            {
                return 0;
            }
            ret = ret * 10 + digit;
        }

        return ret;
    }
};

class Solution2
{
public:
    int reverse(int x)
    {
        int res = 0;
        // 他人的解法，效率较高
        while (x != 0)
        {
            if (res > INT_MAX / 10)
                return 0;
            if (res < INT_MIN / 10)
                return 0;
            res *= 10;
            res = res + x % 10;
            x = x / 10;
        }
        return res;
    }

}

int
main()
{
    int i = -123;
    // while (i != 0)
    // {
    //     cout << i % 10 << endl;
    //     i /= 10;
    // }
    Solution slv;
    cout << slv.reverse(i) << endl;
    return 0;
}