#include <vector>
#include <string>

using std::string;
using std::vector;

// 51. N 皇后
// n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 上图为 8 皇后问题的一种解法。
// 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

// 示例：
// 输入：4
// 输出：[
//  [".Q..",  // 解法 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // 解法 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// 解释: 4 皇后问题存在两个不同的解法。
// 提示：
//     皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/n-queens
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n)
    {
        // '.' 表示空，'Q' 表示皇后，初始化空棋盘。
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    // 路径：board 中小于 row 的那些行都已经成功放置了皇后
    // 选择列表：第 row 行的所有列都是放置皇后的选择
    // 结束条件：row 超过 board 的最后一行
    void backtrack(vector<string> &board, int row)
    {
        // 终止条件
        if (row == board.size())
        {
            res.push_back(board);
            return;
        }

        int cols = board[row].size();
        for (int col = 0; col < cols; col++)
        {
            if (!isValid(board, row, col))
            {
                continue;
            }
            board[row][col] = 'Q'; // 做选择
            backtrack(board, row + 1);
            board[row][col] = '.'; // 撤销选择
        }
    }

    bool isValid(const vector<string> &board, int row, int col)
    {
        int rows = board.size();
        int cols = board.size(); // 列数等于行数

        // 检查列上是否有冲突
        for (int i = 0; i < rows; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // 检查右上方是否有冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < cols; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // 检查左上方是否有冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}