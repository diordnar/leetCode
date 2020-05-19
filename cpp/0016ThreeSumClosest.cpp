#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
// 16. 最接近的三数之和
// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
// 返回这三个数的和。假定每组输入只存在唯一答案。

// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/3sum-closest
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        int delta = INT_MAX;
        for (int i = 0; i < len; ++i)
        {
            int left = i + 1;
            int right = len - 1;

            while (left < right)
            {
                int currsum = nums[i] + nums[left] + nums[right];
                int currdelta = abs(currsum - target);

                if (currdelta < delta)
                {
                    delta = currdelta;
                    sum = currsum;
                }

                if (currsum == target)
                {
                    return currsum;
                }
                else if (currsum < target)
                {
                    ++left;
                }
                else if (currsum > target)
                {
                    --right;
                }
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> vec{1, 1, 1, 0};
    Solution slv;
    cout << slv.threeSumClosest(vec, -100) << endl;
    return 0;
}