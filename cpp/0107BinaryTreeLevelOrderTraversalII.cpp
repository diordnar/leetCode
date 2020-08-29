// 107. 二叉树的层次遍历 II
// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回其自底向上的层次遍历为：
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <vector>
#include <queue>
#include <algorithm>

using std::queue;
using std::reverse;
using std::vector;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root == nullptr)
        {
            return res;
        }

        q.push(root);

        while (!q.empty())
        {
            vector<int> vec;
            int sz = q.size();
            while (sz--)
            {
                TreeNode *node = q.front();
                q.pop();
                vec.push_back(node->val);

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
            }
            res.push_back(vec);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}