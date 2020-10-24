// 112. 路径总和
// 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

// 说明: 叶子节点是指没有子节点的节点。

// 示例:
// 给定如下二叉树，以及目标和 sum = 22，

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1

// 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/path-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <queue>

using std::queue;

//   Definition for a binary tree node.
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
    // BFS
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }

        queue<TreeNode *> nodes;
        queue<int> values;
        nodes.push(root);
        values.push(root->val);

        while (!nodes.empty())
        {
            TreeNode *currNode = nodes.front();
            int currVal = values.front();
            nodes.pop();
            values.pop();

            if (currNode->left == nullptr && currNode->right == nullptr)
            {
                if (currVal == sum)
                {
                    return true;
                }
                continue;
            }

            if (currNode->left != nullptr)
            {
                nodes.push(currNode->left);
                values.push(currVal + currNode->left->val);
            }

            if (currNode->right != nullptr)
            {
                nodes.push(currNode->right);
                values.push(currVal + currNode->right->val);
            }
        }

        return false;
    }
};

class Solution2
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};