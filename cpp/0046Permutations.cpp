#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 46. 全排列
// 给定一个没有重复数字的序列，返回其所有可能的全排列。

// 示例:
// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/permutations
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        n_size = nums.size();

        backtrack(nums);
        return res;
    }

    void backtrack(vector<int> nums)
    {
        if (n_size == path.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            vector<int> tmp(nums);
            tmp.erase(tmp.begin() + i);
            backtrack(tmp);
            path.pop_back();
        }
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    int n_size;
};

class Solution2
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> track;
        backtrack(nums, track);
        return res;
    }

    void backtrack(vector<int> &nums, vector<int> &track)
    {
        if (nums.size() == track.size())
        {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (track.end() != find(track.begin(), track.end(), nums[i]))
            {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
    }

private:
    vector<vector<int>> res;
};

class Solution3
{
public:
    void backtrack(int n, vector<int> &nums, vector<vector<int>> &ans, int first)
    {
        if (first == n - 1)
            ans.push_back(nums);
        else
        {
            for (int i = first; i != n; ++i)
            {
                swap(nums[first], nums[i]);
                backtrack(n, nums, ans, first + 1);
                swap(nums[first], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        backtrack(nums.size(), nums, ans, 0);
        return ans;
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
    Solution2 slv2;
    vector<vector<int>> vecs = slv2.permute(nums);
    for (auto v : vecs)
    {
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}