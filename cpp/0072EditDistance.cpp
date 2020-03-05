#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

// 72.编辑距离
// 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

// 你可以对一个单词进行如下三种操作：

//     插入一个字符
//     删除一个字符
//     替换一个字符

// 示例 1:

// 输入: word1 = "horse", word2 = "ros"
// 输出: 3
// 解释:
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')

// 示例 2:

// 输入: word1 = "intention", word2 = "execution"
// 输出: 5
// 解释:
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/edit-distance
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    // word1[i]!=word2[j]时: dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1
    // word1[i]==word2[j]时: dp[i][j] = dp[i-1][j-1]
    int minDistance(string word1, string word2)
    {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i <= len1; ++i)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= len2; ++j)
        {
            dp[0][j] = j;
        }
        //集合表示 dp[i][j] 对前i个字符进行操作,转换为目标的前j个字符的操作次数 属性->操作次数最小值

        //集合划分 dp[i][j]的来源  考虑对第i个字符进行的操作是什么
        //1 插入操作 从而相等 所以先让前i个字符变为j-1字符，然后在第i处插入j代表的字符 即dp[i][j-1]+1
        //2 删除操作 从而相等 所以先让前i-1个字符变为j字符，然后在第i处删除 即dp[i-1][j]+1
        //3 替换操作 从而相等 if(i处等于j处 不需要替换) 即dp[i-1][j-1]
        //                   else 需要替换 dp[i-1][j-1]+1
        //上述取个最小值即可
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; ++j)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};

int main()
{

    return 0;
}