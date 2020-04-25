#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 268. 缺失数字
// 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
// 示例 1:
// 输入: [3,0,1]
// 输出: 2

// 示例 2:
// 输入: [9,6,4,2,3,5,7,0,1]
// 输出: 8

// 说明:
// 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/missing-number
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (i != nums[i])
            {
                return i;
            }
        }

        return len;
    }
};

class Solution2
{
public:
    int missingNumber(vector<int> &nums)
    {
        // 对于异或运算（^），我们知道它有一个特殊性质：一个数和它本身做异或运算结果为 0，
        // 一个数和 0 做异或运算还是它本身。
        // 而且异或运算满足交换律和结合律，也就是说：
        // 2 ^ 3 ^ 2 = 3 ^ (2 ^ 2) = 3 ^ 0 = 3
        int len = nums.size();
        int res = 0;
        res ^= len;
        for (int i = 0; i < len; ++i)
        {
            res ^= i ^ nums[i];
        }
        return res;
    }
};

class Solution3
{
public:
    int missingNumber(vector<int> &nums)
    {
        int len = nums.size();
        int res = 0;
        res = len - 0;
        for (int i = 0; i < len; ++i)
        {
            res += i - nums[i];
        }
        return res;
    }
};

int main()
{
    return 0;
}