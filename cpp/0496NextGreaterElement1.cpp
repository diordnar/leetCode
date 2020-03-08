#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// 496. 下一个更大元素 I
// 给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2
// 中的下一个比其大的值。

// nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，
// 对应位置输出-1。

// 示例 1:
// 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
// 输出: [-1,3,-1]
// 解释:
//     对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
//     对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
//     对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。

// 示例 2:
// 输入: nums1 = [2,4], nums2 = [1,2,3,4].
// 输出: [3,-1]
// 解释:
//     对于num1中的数字2，第二个数组中的下一个较大数字是3。
//     对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/next-greater-element-i
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> vec;
        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                if (nums1[i] == nums2[j])
                {
                    int m = j + 1;
                    for (; m < nums2.size(); ++m)
                    {
                        if (nums2[j] < nums2[m])
                        {
                            vec.push_back(nums2[m]);
                            break;
                        }
                    }
                    if (m == nums2.size())
                    {
                        vec.push_back(-1);
                    }
                    break;
                }
            }
        }
        return vec;
    }
};

class Solution1
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> ans;
        unordered_map<int, int> umap;
        stack<int> stk;

        // 单调栈
        for (int i = nums2.size() - 1; i >= 0; --i) // 倒着入栈
        {
            while (!stk.empty() && stk.top() < nums2[i])
            {
                stk.pop(); // 比当前数小的都弹出
            }
            int tmp = stk.empty() ? -1 : stk.top();
            umap.insert({nums2[i], tmp});
            stk.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); ++i)
        {
            ans.push_back(umap[nums1[i]]);
        }

        return ans;
    }
};

class Solution2
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        for (auto num : nums2)
        {
            while (!sk1.empty() && num > sk1.top())
            {
                mp1[sk1.top()] = num;
                sk1.pop();
            }
            sk1.push(num);
        }
        vector<int> ans;
        for (auto num : nums1)
        {
            if (mp1.find(num) == mp1.end())
                ans.push_back(-1);
            else
                ans.push_back(mp1[num]);
        }
        return ans;
    }

private:
    unordered_map<int, int> mp1;
    stack<int> sk1;
};

int main()
{
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    Solution slv;
    slv.nextGreaterElement(nums1, nums2);
    Solution1 slv1;
    slv1.nextGreaterElement(nums1, nums2);
    return 0;
}