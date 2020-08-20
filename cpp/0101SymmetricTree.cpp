// 给定一个二叉树，检查它是否是镜像对称的。
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3

// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//     1
//    / \
//   2   2
//    \   \
//    3    3

// 进阶：
// 你可以运用递归和迭代两种方法解决这个问题吗？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/symmetric-tree
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return check(root->left, root->right);
    }

    bool check(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
    }
};

int main()
{
    return 0;
}
