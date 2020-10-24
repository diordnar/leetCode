#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;
using std::reverse;
using std::unordered_map;
using std::vector;

// 113. 路径总和 II
// 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
// 说明: 叶子节点是指没有子节点的节点。
// 示例:
// 给定如下二叉树，以及目标和 sum = 22，
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// 返回:
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/path-sum-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *_left, TreeNode *_right) : val(x), left(_left), right(_right) {}
};

// 113. 路径和II
// BFS
class Solution
{
public:
    vector<vector<int>> res;
    // [子节点，父节点]
    unordered_map<TreeNode *, TreeNode *> parentNodes;

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return res;
        }

        queue<TreeNode *> nodes;
        queue<int> values;

        nodes.push(root);
        values.push(root->val);

        while (!nodes.empty())
        {
            TreeNode *currNode = nodes.front();
            nodes.pop();
            int currVal = values.front();
            values.pop();
            if (currNode->left == nullptr && currNode->right == nullptr)
            {
                if (currVal == sum)
                {
                    res.push_back(getPath(currNode)); // 将满足条件的路径放到结果中
                }
            }

            if (currNode->left != nullptr)
            {
                nodes.push(currNode->left);
                values.push(currNode->left->val + currVal);
                parentNodes[currNode->left] = currNode; // 子节点为Key, 父节点为Value
            }

            if (currNode->right != nullptr)
            {
                nodes.push(currNode->right);
                values.push(currNode->right->val + currVal);
                parentNodes[currNode->right] = currNode; // 子节点为Key, 父节点为Value
            }
        }
        return res;
    }

    vector<int> getPath(TreeNode *node)
    {
        vector<int> path;
        while (node != nullptr)
        {
            // 从叶子节点将各个节点的值放入path中
            path.push_back(node->val);
            // 获得当前节点的父节点，根节点无父节点，parentNodes[node]为默认值nullptr
            node = parentNodes[node];
        }
        // path中的值的存储顺序为叶子节点-->根节点，需要反转
        reverse(path.begin(), path.end());
        return path;
    }
};

// 113. 路径和II
// DFS
class Solution2
{
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        dfs(root, sum);
        return res;
    }

    void dfs(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return;
        }
        path.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0)
        {
            res.push_back(path);
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
    }
};

class Solution3
{
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return res;
        }
        path.push_back(root->val);
        dfs(root, sum - root->val);
        return res;
    }

    void dfs(TreeNode *root, int sum)
    {
        if (root->left == nullptr && root->right == nullptr && sum == 0)
        {
            res.push_back(path);
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return;
        }
        if (root->left)
        {
            path.push_back(root->left->val); // 选择
            sum -= root->left->val;
            dfs(root->left, sum);
            sum += root->left->val; // 回溯
            path.pop_back();        // 回溯
        }
        if (root->right)
        {
            path.push_back(root->right->val); // 选择
            sum -= root->right->val;
            dfs(root->right, sum);
            sum += root->right->val; // 回溯
            path.pop_back();         // 回溯
        }
    }
};

int main()
{
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    TreeNode *root = new TreeNode(1, left, right);

    int sum = 4;

    Solution2 slv2;
    auto res = slv2.pathSum(root, sum);
    for (auto vec : res)
    {
        for (auto i : vec)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}