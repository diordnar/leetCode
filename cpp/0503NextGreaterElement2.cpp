#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// 503. 下一个更大元素 II
// 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
// 数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的
// 下一个更大的数。如果不存在，则输出 -1。

// 示例 1:
// 输入: [1,2,1]
// 输出: [2,-1,2]
// 解释: 第一个 1 的下一个更大的数是 2；
// 数字 2 找不到下一个更大的数；
// 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。

// 注意: 输入数组的长度不会超过 10000。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/next-greater-element-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {

        stack<int> stk;
        int sz = nums.size();
        vector<int> ans(sz);
        for (int i = 2 * sz - 1; i >= 0; --i)
        {
            while (!stk.empty() && stk.top() <= nums[i % sz])
            {
                stk.pop();
            }
            ans[i % sz] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i % sz]);
        }

        return ans;
    }
};

class Solution2
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1); //技巧：提前都初始化为-1，减少后面重新赋值的步骤

        for (int i = 0; i < 2 * n; ++i)
        {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num)
            {
                res[st.top()] = num;
                st.pop();
            }
            if (i < n)
                st.push(i); //下标进栈
        }
        return res;
    }

private:
    stack<int> st;
};

int main()
{
    vector<int> nums1 = {1, 2, 1}, nums2 = {1, 3, 4, 2};
    Solution slv;
    slv.nextGreaterElements(nums1);
    return 0;
}