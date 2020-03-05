#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// 877. 石子游戏
// 亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。
// 游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
// 亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。
// 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
// 假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。

// 示例：
// 输入：[5,3,4,5]
// 输出：true
// 解释：
// 亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
// 假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
// 如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
// 如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
// 这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。

// 提示：
//     2 <= piles.length <= 500
//     piles.length 是偶数。
//     1 <= piles[i] <= 500
//     sum(piles) 是奇数。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/stone-game
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        typedef pair<int, int> Pair;
        int n = piles.size();
        vector<vector<Pair>> dp(n, vector<Pair>(n));

        // Base case
        for (int i = 0; i < n; ++i)
        {
            dp[i][i].first = piles[i];
            dp[i][i].second = 0;
        }

        // 从下往上，从左往右遍历
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int left = piles[i] + dp[i + 1][j].second;
                int right = piles[j] + dp[i][j - 1].second;

                if (left > right) // 先手选择左边
                {
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i + 1][j].first;
                }
                else // 先手选择右边
                {
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j - 1].first;
                }
            }
        }
        return dp[0][n - 1].first > dp[0][n - 1].second;
    }
};

class Solution2
{
public:
    bool stoneGame(vector<int> &piles)
    {
        typedef pair<int, int> Pair;
        int n = piles.size();
        vector<vector<Pair>> dp(n, vector<Pair>(n));

        // Base case
        for (int i = 0; i < n; ++i)
        {
            dp[i][i].first = piles[i];
            dp[i][i].second = 0;
        }

        // 斜着遍历
        for (int m = 2; m <= n; ++m)
        {
            for (int i = 0; i <= n - m; ++i)
            {
                int j = m + i - 1;
                int left = piles[i] + dp[i + 1][j].second;
                int right = piles[j] + dp[i][j - 1].second;

                if (left > right) // 先手选择左边
                {
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i + 1][j].first;
                }
                else // 先手选择右边
                {
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j - 1].first;
                }
            }
        }
        return dp[0][n - 1].first > dp[0][n - 1].second;
    }
};

int main()
{
    vector<int> piles{5, 3, 4, 5};

    cout << boolalpha << Solution().stoneGame(piles) << endl;
    cout << boolalpha << Solution2().stoneGame(piles) << endl;
    return 0;
}