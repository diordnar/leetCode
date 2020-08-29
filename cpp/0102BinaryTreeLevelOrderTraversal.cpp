/*
 * @Description: 
 * @Author: 徐小明
 * @Date: 2020-08-24 20:47:14
 * @LastEditors: 徐小明
 * @LastEditTime: 2020-08-24 21:30:08
 * @FilePath: \cpp\0102BinaryTreeLevelOrderTraversal.cpp
 */
// 102. 二叉树的层序遍历
// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
// 示例：
// 二叉树：[3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其层次遍历结果：

// [
//   [3],
//   [9,20],
//   [15,7]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <vector>
#include <queue>

using std::queue;
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> vec;
            while (sz > 0)
            {
                TreeNode *node = q.front();
                vec.push_back(node->val);
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
                --sz;
            }
            res.push_back(vec);
        }
        return res;
    }
};

int main()
{
    Solution slv;
    return 0;
}