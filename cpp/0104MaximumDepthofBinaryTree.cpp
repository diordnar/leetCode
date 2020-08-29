// 给定一个二叉树，找出其最大深度。

// 104. 二叉树的最大深度
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
// 说明: 叶子节点是指没有子节点的节点。
// 示例：
// 给定二叉树 [3,9,20,null,null,15,7]，
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最大深度 3 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <queue>
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int max = 0;
        return helper(root, max);
    }

    int helper(TreeNode *root, int max)
    {
        if (root == nullptr)
        {
            return max;
        }
        int lmax = helper(root->left, max + 1);
        int rmax = helper(root->right, max + 1);
        return lmax > rmax ? lmax : rmax;
    }
};

// 递归
class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// BFS
using std::queue;
class Solution3
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<TreeNode *> qk;
        qk.push(root);
        int ans = 0;
        while (!qk.empty())
        {
            int sz = qk.size();
            while (sz > 0)
            {
                TreeNode *node = qk.front();
                qk.pop();
                if (node->left)
                {
                    qk.push(node->left);
                }
                if (node->right)
                {
                    qk.push(node->right);
                }
                --sz;
            }
            ++ans;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
