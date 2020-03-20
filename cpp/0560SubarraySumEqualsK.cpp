#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 560. 和为K的子数组
// 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
// 示例 1 :
// 输入:nums = [1,1,1], k = 2
// 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
// 说明 :
//     数组的长度为 [1, 20,000]。
//     数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // max sum of array = 20000 * 1000 = 20,000,000 < INT_MAX
        // min sum of array = 20000 * -1000 = -20,000,000 > INT_MIN
        int len = nums.size();
        vector<int> preSum(len + 1, 0);
        int cnt = 0;
        for (int i = 0; i < len; ++i)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j <= len; ++j)
            {
                if (preSum[j] - preSum[i] == k)
                {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

class Solution2
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // max sum of array = 20000 * 1000 = 20,000,000 < INT_MAX
        // min sum of array = 20000 * -1000 = -20,000,000 > INT_MIN
        int len = nums.size();
        unordered_map<int, int> umap;
        umap[0] = 1;
        int cnt = 0;
        int sum = 0;

        for (int i = 0; i < len; ++i)
        {
            sum = sum + nums[i];
            int minus = sum - k;
            if (umap.count(minus))
            {
                cnt += umap[minus];
            }
            ++umap[sum];
        }
        return cnt;
    }
};

int main()
{
    vector<int> vec{3, 5, 2, -2, 4, 1};
    int k = 5;
    Solution slv;
    cout << slv.subarraySum(vec, k) << endl;
    Solution2 slv2;
    cout << slv2.subarraySum(vec, k) << endl;
    return 0;
}