#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 645. 错误的集合
// 集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，
// 导致集合丢失了一个整数并且有一个元素重复。
// 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，
// 将它们以数组的形式返回。

// 示例 1:
// 输入: nums = [1,2,2,4]
// 输出: [2,3]

// 注意:
//     给定数组的长度范围是 [2, 10000]。
//     给定的数组是无序的。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/set-mismatch
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        // 暴力解法,超时
        int missing = -1;
        int dup = -1;
        int sz = nums.size();
        for (int i = 1; i <= sz; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < sz; ++j)
            {
                if (nums[j] == i)
                {
                    ++cnt;
                }
            }
            if (cnt == 2)
            {
                dup = i;
            }
            else if (cnt == 0)
            {
                missing = i;
            }

            if (dup > 0 && missing > 0)
            {
                break;
            }
        }

        return {dup, missing};
    }
};

class Solution2
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        // 使用排序
        int missing = 1;
        int dup = -1;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < sz; ++i)
        {
            if (nums[i - 1] == nums[i])
            {
                dup = nums[i];
            }
            else if (nums[i] > nums[i - 1] + 1)
            {
                missing = nums[i - 1] + 1;
            }
        }

        return {dup, nums[sz - 1] != sz ? sz : missing};
    }
};

class Solution3
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        // 使用unordered_map
        int missing = -1;
        int dup = -1;
        int sz = nums.size();
        unordered_map<int, int> table;
        for (int i = 0; i < sz; ++i)
        {
            table[nums[i]]++;
        }
        for (int i = 1; i <= sz; ++i)
        {
            if (table.count(i))
            {
                if (2 == table[i])
                {
                    dup = i;
                }
            }
            else
            {
                missing = i;
            }
        }

        return {dup, missing};
    }
};
class Solution4
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        //  思路分析

        // 这个问题的特点是，每个元素和数组索引有一定的对应关系。
        // 我们现在自己改造下问题，暂且将 nums 中的元素变为 [0..N-1]，这样每个元素就和一个数组索引完全对应了，
        // 这样方便理解一些。
        // 如果说 nums 中不存在重复元素和缺失元素，那么每个元素就和唯一一个索引值对应，对吧？
        // 现在的问题是，有一个元素重复了，同时导致一个元素缺失了，这会产生什么现象呢？会导致有两个元素对应到了同一个索引，
        // 而且会有一个索引没有元素对应过去。
        // 那么，如果我能够通过某些方法，找到这个重复对应的索引，不就是找到了那个重复元素么？找到那个没有元素对应的索引，
        // 不就是找到了那个缺失的元素了么？
        // 那么，如何不使用额外空间判断某个索引有多少个元素对应呢？这就是这个问题的精妙之处了：
        // 通过将每个索引对应的元素变成负数，以表示这个索引被对应过一次了：
        int missing = -1;
        int dup = -1;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                dup = abs(nums[i]);
            }
            else
            {
                nums[index] *= -1;
            }
        }

        for (int i = 0; i < sz; ++i)
        {
            if (nums[i] > 0)
            {
                missing = i + 1;
            }
        }
        return {dup, missing};
    }
};

class Solution5
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        // LeetCode时间短的解决方案
        int erro_num = -1;
        int n = nums.size();
        int sum = (1 + n) * n / 2;
        for (auto &&i : nums)
        {
            int index = abs(i);
            if (nums[index - 1] < 0)
                erro_num = index;
            nums[index - 1] *= -1;
            sum -= index;
        }
        std::vector<int> ans;
        ans.push_back(erro_num);
        ans.push_back(erro_num + sum);
        return ans;
    }
};

int main()
{
    return 0;
}