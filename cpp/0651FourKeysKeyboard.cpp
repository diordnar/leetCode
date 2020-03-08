#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>

using namespace std;
// 这种思路稍微有点复杂，但是效率高。继续走流程，「选择」还是那 4 个，但是这次我们只定义一个「状态」，
// 也就是剩余的敲击次数 n。
// 这个算法基于这样一个事实，最优按键序列一定只有两种情况：
// 要么一直按 A：A,A,...A（当 N 比较小时）。
// 要么是这么一个形式：A,A,...C-A,C-C,C-V,C-V,...C-V（当 N 比较大时）。
// 因为字符数量少（N 比较小）时，C-A C-C C-V 这一套操作的代价相对比较高，可能不如一个个按 A；
// 而当 N 比较大时，后期 C-V 的收获肯定很大。这种情况下整个操作序列大致是：开头连按几个 A，然后 C-A C-C 组合再接若干 C-V，然后再 C-A C-C 接着若干 C-V，循环下去。
// 换句话说，最后一次按键要么是 A 要么是 C-V。明确了这一点，可以通过这两种情况来设计算法：
// int[] dp = new int[N + 1];
// // 定义：dp[i] 表示 i 次操作后最多能显示多少个 A
// for (int i = 0; i <= N; i++)
//     dp[i] = max(
//             这次按 A 键，
//             这次按 C-V
//         )
// 对于「按 A 键」这种情况，就是状态 i - 1 的屏幕上新增了一个 A 而已，很容易得到结果：
// // 按 A 键，就比上次多一个 A 而已
// dp[i] = dp[i - 1] + 1;
// 但是，如果要按 C-V，还要考虑之前是在哪里 C-A C-C 的。
// 刚才说了，最优的操作序列一定是 C-A C-C 接着若干 C-V，所以我们用一个变量 j 作为若干 C-V 的起点。
// 那么 j 之前的 2 个操作就应该是 C-A C-C 了：
// public int maxA(int N) {
//     int[] dp = new int[N + 1];
//     dp[0] = 0;
//     for (int i = 1; i <= N; i++) {
//         // 按 A 键
//         dp[i] = dp[i - 1] + 1;
//         for (int j = 2; j < i; j++) {
//             // 全选 & 复制 dp[j-2]，连续粘贴 i - j 次
//             // 屏幕上共 dp[j - 2] * (i - j + 1) 个 A
//             dp[i] = Math.max(dp[i], dp[j - 2] * (i - j + 1));
//         }
//     }
//     // N 次按键之后最多有几个 A？
//     return dp[N];
// }
// 其中 j 变量减 2 是给 C-A C-C 留下操作数，看个图就明白了：
class Solution
{
public:
    int maxA(int N)
    {
        vector<int> dp(N + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= N; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j < i; ++j)
            {
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
            }
        }
        return dp[N];
    }
};

int main()
{
    // N=3 output: 3
    // N=7 output: 9
    Solution slv;
    cout << slv.maxA(3) << endl;
    cout << slv.maxA(7) << endl;
    cout << slv.maxA(20) << endl;
    return 0;
}