#include <iostream>
#include <vector>
#include <cmath> // c++11 log2()
using namespace std;
// 342. 4的幂
// 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

// 示例 1:
// 输入: 16
// 输出: true

// 示例 2:
// 输入: 5
// 输出: false

// 进阶：
// 你能不使用循环或者递归来完成本题吗？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/power-of-four
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0)
        {
            return false;
        }
        int mask = 0x55555555; // 4的幂满足 0101 0101
        if (num & (num - 1))   // 2^N 二进制只有一个1
        {
            return false; // 不是2的幂，肯定不是4的幂
        }
        if ((num ^ mask) & (~mask)) // 判断 num的二进制1是否在满足4的幂的位置上
        {
            return false;
        }
        return true;
    }
};
class Solution2
{
public:
    bool isPowerOfFour(int num) // 4^N = 2^2N
    {
        if (num <= 0)
            return false;

        if (num & (num - 1))
        {
            return false;
        }
        int n = log2(num); // c++11
        if (n & 0x01)      // n % 2
        {
            return false;
        }
        return true;
    }
};

class Solution3
{
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0)
            return false;
        return ((num - 1) & num) == 0 && (num - 1) % 3 == 0;
    }
};

int main()
{
    vector<int> vec{1, 2, 8, 16, 64, 128, 256, -1, -4};
    Solution slv;
    for (auto i : vec)
    {
        cout << boolalpha << slv.isPowerOfFour(i) << endl;
    }
    cout << "*********************************************\n";
    Solution2 slv2;
    for (auto i : vec)
    {
        cout << boolalpha << slv2.isPowerOfFour(i) << endl;
    }
    return 0;
}