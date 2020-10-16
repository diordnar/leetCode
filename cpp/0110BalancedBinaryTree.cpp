#include <algorithm>
#include <cmath>
using std::abs;
using std::max;

// 110. 平衡二叉树

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

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
    }

    int height(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return max(height(node->left), height(node->right)) + 1;
    }
};

class Solution1
{
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }

    int height(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int left = height(node->left);
        if (left == -1)
        {
            return -1;
        }
        int right = height(node->right);
        if (right == -1)
        {
            return -1;
        }

        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
};