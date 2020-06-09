// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 你的算法时间复杂度必须是 O(log n) 级别。
// 如果数组中不存在目标值，返回 [-1, -1]。
// 示例 1:
// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]

// 示例 2:
// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res;
        res.push_back(left_bound(nums, target));
        res.push_back(right_bound(nums, target));
        return res;
    }

private:
    int left_bound(vector<int> &nums, int target)
    {
        int sz = nums.size();
        if (sz == 0)
        {
            return -1;
        }
        int left = 0, right = sz - 1;
        // 左闭右闭区间搜索，搜索情况划分为小于目标，等于目标，大于目标
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                right = mid - 1; // 向左收缩
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }
        if (left >= sz || nums[left] != target)
        {
            return -1;
        }
        return left;
    }

    int right_bound(vector<int> &nums, int target)
    {
        int sz = nums.size();
        if (sz == 0)
        {
            return -1;
        }
        int left = 0, right = sz - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                left = mid + 1; // 向右收缩
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }
        if (right < 0 || nums[right] != target)
        {
            return -1;
        }
        return right;
    }
};

class Solution2
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res;
        res.push_back(left_bound(nums, target));
        res.push_back(right_bound(nums, target));
        return res;
    }

private:
    int left_bound(vector<int> &nums, int target)
    {
        int sz = nums.size();
        if (sz == 0)
        {
            return -1;
        }
        int left = 0, right = sz - 1;
        // 左闭右开区间搜索，搜索情况划分为不满足，可能满足
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) // 不满足要求
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (nums[left] != target)
        {
            return -1;
        }

        return left;
    }

    int right_bound(vector<int> &nums, int target)
    {
        int sz = nums.size();
        if (sz == 0)
        {
            return -1;
        }
        int left = 0, right = sz - 1;
        // 左闭右开区间搜索，搜索情况划分为不满足，可能满足
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2; // 向上取整，不然可能会死循环
            if (nums[mid] > target)
            {
                right = mid - 1; // 不满足要求
            }
            else
            {
                left = mid;
            }
        }
        if (nums[left] != target)
        {
            return -1;
        }
        return left;
    }
};

int main()
{
    return 0;
}