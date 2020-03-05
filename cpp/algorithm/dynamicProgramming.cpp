#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 总结一下动态规划的设计流程：
// 首先明确 dp 数组所存数据的含义。这步很重要，如果不得当或者不够清晰，会阻碍之后的步骤。
// 然后根据 dp 数组的定义，运用数学归纳法的思想，假设 dp[0...i−1] 都已知，想办法求出
// dp[i]，一旦这一步完成，整个题目基本就解决了。
// 但如果无法完成这一步，很可能就是 dp 数组的定义不够恰当，需要重新定义 dp 数组的含义；或者可能是 dp
// 数组存储的信息还不够，不足以推出下一步的答案，需要把 dp 数组扩大成二维数组甚至三维数组。
// 最后想一想问题的 base case 是什么，以此来初始化 dp 数组,以保证算法正确运行。

// 凑零钱问题
// 题目：给你 k 种面值的硬币，面值分别为 c1, c2 ... ck，再给一个总金额 n，问你最少需要几枚硬币凑出这个金额，
// 如果不可能凑出，则回答 -1 。
// 比如说，k = 3，面值分别为 1，2，5，总金额 n = 11，那么最少需要 3 枚硬币，即 11 = 5 + 5 + 1 。下面走流程。
int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return -1;
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {

        for (auto coin : coins)
        {
            if (i - coin < 0)
                continue;
            dp[i] = min(dp[i - coin] + 1, dp[i]);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    cout << "Coin Change" << endl;
    vector<int> coins{1, 2, 5};
    cout << coinChange(coins, 11) << endl;
    return 0;
}