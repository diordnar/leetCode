/*
 * @Description: 
 * @Author: 徐小明
 * @Date: 2020-05-31 14:46:05
 * @LastEditors: 徐小明
 * @LastEditTime: 2020-05-31 18:07:16
 * @FilePath: \cpp\0035SearchInsertPosition.cpp
 */

// 35. Search Insert Position
// 35. 搜索插入位置
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，
// 返回它将会被按顺序插入的位置。
// 你可以假设数组中无重复元素。
// 示例 1:
// 输入: [1,3,5,6], 5
// 输出: 2

// 示例 2:
// 输入: [1,3,5,6], 2
// 输出: 1

// 示例 3:
// 输入: [1,3,5,6], 7
// 输出: 4

// 示例 4:
// 输入: [1,3,5,6], 0
// 输出: 0

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/search-insert-position
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Binary Search
    int searchInsert(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }

        if (target <= nums[0])
        {
            return 0;
        }
        if (target > nums[len - 1])
        {
            return len;
        }

        int left = 0;
        int right = len - 1;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
class Solution1
{
public:
    // Binary Search
    int searchInsert(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        if (target < nums[0])
        {
            return 0;
        }
        if (target > nums[len - 1])
        {
            return len;
        }
        int left = 0;
        int right = len - 1;
        int mid;
        while (left <= right)
        {
            mid = right - (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        if (nums[mid] < target)
        {
            return mid + 1;
        }
        return mid;
    }
};

class Solution2
{
public:
    // Brute Force
    int searchInsert(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        if (target <= nums[0])
        {
            return 0;
        }
        if (target > nums[len - 1])
        {
            return len;
        }
        int prev;
        int curr;
        int i = 1;
        for (; i < len; ++i)
        {
            curr = nums[i];
            prev = nums[i - 1];
            if (curr == target)
            {
                return i;
            }
            if (prev < target && curr > target)
            {
                return i;
            }
        }
        return i;
    }
};

int main()
{
    return 0;
}
