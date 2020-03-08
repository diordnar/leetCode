#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;
// 337. 打家劫舍 III
// 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
// 这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
// 一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
//  如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
// 示例 1:
// 输入: [3,2,3,null,3,null,1]
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
// 输出: 7
// 解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

// 示例 2:
// 输入: [3,4,5,1,3,null,1]
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1

// 输出: 9
// 解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/house-robber-iii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int rob(TreeNode *root)
    {
        auto ret = dp(root);
        return max(ret.first, ret.second);
    }

    // 返回值: first：不包含当前节点的金额； second:包含当前节点的金额
    pair<int, int> dp(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {0, 0};
        }

        auto left = dp(root->left);
        auto right = dp(root->right);

        return {max(left.first, left.second) + max(right.first, right.second),
                root->val + left.first + right.first};
    }
};

// Java
/* 返回一个大小为 2 的数组 arr
arr[0] 表示不抢 root 的话，得到的最大钱数
arr[1] 表示抢 root 的话，得到的最大钱数 */
// int[] dp(TreeNode root) {
//     if (root == null)
//         return new int[]{0, 0};
//     int[] left = dp(root.left);
//     int[] right = dp(root.right);
//     // 抢，下家就不能抢了
//     int rob = root.val + left[0] + right[0];
//     // 不抢，下家可抢可不抢，取决于收益大小
//     int not_rob = Math.max(left[0], left[1])
//                 + Math.max(right[0], right[1]);

//     return new int[]{not_rob, rob};
// }
// int rob(TreeNode root)
// {
//     int[] res = dp(root);
//     return Math.max(res[0], res[1]);
// }

// 思路
// 建议先使用动态规划的方法做 打家劫舍 I 之后在做这道题，大体思路相同。
// 和打家劫舍I一样，不能选择相邻的两个节点。所以对于一个子树来说，有两种情况：
//     包含当前根节点
//     不包含当前根节点

// 情况1：包含根节点
// 由于包含了根节点，所以不能选择左右儿子节点，这种情况的最大值为：当前节点 + 左儿子情况2 + 右二子情况2
// 情况2：不包含根节点
// 这种情况，可以选择左右儿子节点，所以有四种可能：

//     左儿子情况1 + 右儿子情况1
//     左儿子情况1 + 右儿子情况2
//     左儿子情况2 + 右儿子情况1
//     左儿子情况2 + 右儿子情况2

// 综合来说就是，max(左儿子情况1, 左儿子情况2) + max(右儿子情况1, 右儿子情况2)。
// 综合两种情况，深度优先，从叶子节点遍历到根节点即可。
// 代码实现

// 由于只有两种情况，可以选择使用pair来存储这两种情况的数据值。
// pair的含义：<情况1包含当前节点的最大值，情况2不包含当前节点的最大值>

// 作者：da-ge-he-cha
// 链接：https://leetcode-cn.com/problems/house-robber-iii/solution/cdong-tai-gui-hua-si-xiang-shi-xian-xiang-xi-shuo-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution9
{
public:
    pair<int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {0, 0};
        }
        auto left_pair = dfs(root->left);
        auto right_pair = dfs(root->right);
        return {root->val + left_pair.second + right_pair.second,
                max(left_pair.first, left_pair.second) + max(right_pair.first, right_pair.second)};
    }

    int rob(TreeNode *root)
    {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};

int main()
{
    return 0;
}