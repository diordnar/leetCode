#include <vector>
#include <iostream>

using namespace std;
// 372. 超级次方
// 你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

// 示例 1:
// 输入: a = 2, b = [3]
// 输出: 8

// 示例 2:
// 输入: a = 2, b = [1,0]
// 输出: 1024

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/super-pow
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    // (a * b) % k = (a % k) * (b % k) % k
    // 证明很简单，假设：
    // a = Ak +B；b = Ck + D
    // 其中 A,B,C,D 是任意常数，那么：
    // ab = ACk^2 + ADk + BCk +BD
    // ab % k = BD % k
    // 又因为：
    // a % k = B；b % k = D
    // 所以：
    // (a % k)(b % k) % k = BD % k

    int superPow(int a, vector<int> &b)
    {
        if (b.empty())
        {
            return 1;
        }
        int last = b.back();
        b.pop_back();
        int part1 = mypow(a, last);
        int part2 = mypow(superPow(a, b), 10);
        return (part1 * part2) % base;
    }

private:
    int mypow(int a, int k)
    {
        a %= base;
        int res = 1;
        for (int i = 0; i < k; ++i)
        {
            res *= a;
            // 每次对乘积求模防止溢出
            res %= base;
        }
        return res;
    }

private:
    static const int base = 1337;
};
int main()
{
    return 0;
}