#include <iostream>
#include <vector>

using namespace std;
// uniform template for binary search
int binary_search(const vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            // left_bound:  right = mid - 1
            // right_bound: left  = mid + 1
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
    // left_bound:
    // if (left >= nums.size() || nums[left] != target)
    // {
    //     return -1
    // };
    // return left;

    // right_bound:
    // if (right < 0 || nums[right] != target)
    // {
    //     return -1;
    // }
    // return right;
    return -1;
}

int left_bound(const vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            right = mid - 1;
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
    if (left >= nums.size() || nums[left] != target)
    {
        return -1;
    }
    return left;
}

int right_bound(const vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            left = mid + 1;
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
    if (right < 0 || nums[right] != target)
    {
        return -1;
    }
    return right;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << binary_search(vec, 4) << endl;
    return 0;
}

