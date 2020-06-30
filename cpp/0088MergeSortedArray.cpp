/*
 * @Description: 
 * @Author: 徐小明
 * @Date: 2020-06-30 12:51:08
 * @LastEditors: 徐小明
 * @LastEditTime: 2020-06-30 14:40:26
 * @FilePath: \cpp\0088MergeSortedArray.cpp
 */
// 88. 合并两个有序数组
// 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

// 说明:
//     初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
//     你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
// 示例:
// 输入:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// 输出: [1,2,2,3,5,6]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/merge-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> vec(nums1);
        int idx = 0;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (vec[i] < nums2[j])
            {
                nums1[idx++] = vec[i++];
            }
            else
            {
                nums1[idx++] = nums2[j++];
            }
        }

        while (i < m)
        {
            nums1[idx++] = vec[i++];
        }

        while (j < n)
        {
            nums1[idx++] = nums2[j++];
        }
    }
};

class Solution2
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int idx = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0)
        {
            nums1[idx--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        copy_n(nums2.begin(), j + 1, nums1.begin());
    }
};

int main()
{
    return 0;
}