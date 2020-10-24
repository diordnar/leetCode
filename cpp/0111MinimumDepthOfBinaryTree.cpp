// 111. 二叉树的最小深度
// 给定一个二叉树，找出其最小深度。
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
// 说明: 叶子节点是指没有子节点的节点。
// 示例:
// 给定二叉树 [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回它的最小深度  2.
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <limits>
#include <algorithm>
#include <queue>
#include <utility>
using std::min;
using std::numeric_limits;
using std::pair;
using std::queue;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Depth first
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        int min_depth = numeric_limits<int>::max();
        if (root->left != nullptr)
        {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr)
        {
            min_depth = min(minDepth(root->right), min_depth);
        }
        return min_depth + 1;
    }
};

// Breadth first
class Solution2
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<pair<TreeNode *, int>> que;
        que.emplace(root, 1);
        while (!que.empty())
        {
            TreeNode *node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (node->left == nullptr && node->right == nullptr)
            {
                return depth;
            }
            if (node->left != nullptr)
            {
                que.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr)
            {
                que.emplace(node->right, depth + 1);
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}