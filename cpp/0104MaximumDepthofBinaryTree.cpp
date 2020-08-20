#include <queue>
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
