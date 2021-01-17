// 100. 相同的树
// 给定两个二叉树，编写一个函数来检验它们是否相同。
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
// 示例 1:
// 输入:       1         1
//           / \       / \
//          2   3     2   3

//         [1,2,3],   [1,2,3]
// 输出: true

// 示例 2:
// 输入:      1          1
//           /           \
//          2             2

//         [1,2],     [1,null,2]
// 输出: false

// 示例 3:
// 输入:       1         1
//           / \       / \
//          2   1     1   2

//         [1,2,1],   [1,1,2]
// 输出: false

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/same-tree
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    return 0;
}