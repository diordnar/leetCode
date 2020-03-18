#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 523. 连续的子数组和
// 给定一个包含非负数的数组和一个目标整数 k，编写一个函数来判断该数组是否含有连续的子数组，
// 其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

// 示例 1:
// 输入: [23,2,4,6,7], k = 6
// 输出: True
// 解释: [2,4] 是一个大小为 2 的子数组，并且和为 6。

// 示例 2:
// 输入: [23,2,6,4,7], k = 6
// 输出: True
// 解释: [23,2,6,4,7]是大小为 5 的子数组，并且和为 42。

// 说明:
//     数组的长度不会超过10,000。
//     你可以认为所有数字总和在 32 位有符号整数范围内。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/continuous-subarray-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> preSum(nums.size() + 1);
        preSum[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                int sum = preSum[j] - preSum[i] + nums[i - 1]; // 数组的长度最少为 2
                if (k == sum || (k != 0 && 0 == sum % k))      // k == sum, [0,0] k=0
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// Java
// class Solution {
//     public boolean checkSubarraySum(int[] nums, int k) {
//         int N = nums.length, cache = 0;
//         int[] sum = new int[N+1];
//         HashSet<Integer> set = new HashSet<>();

//         for (int i = 0; i < N; i++) {
//             sum[i+1] = sum[i] + nums[i];
//             int res = k == 0 ? sum[i+1] : sum[i+1] % k;
//             if (set.contains(res)) return true;
//             set.add(cache);
//             cache = res;
//         }

//         return false;
//     }
// }
//https://leetcode-cn.com/problems/continuous-subarray-sum/solution/lian-xu-de-zi-shu-zu-qiu-he-by-lenn123/
class Solution2
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int cache = 0;
        int len = nums.size();
        unordered_set<int> set;
        vector<int> sum(len + 1, 0);
        for (int i = 0; i < len; ++i)
        {
            sum[i + 1] = sum[i] + nums[i];
            int res = k == 0 ? sum[i + 1] : sum[i + 1] % k;
            if (set.find(res) != set.end())
            {
                return true;
            }

            set.insert(cache); // 要求数组的长度为2，利用缓存延迟加入set中
            cache = res;
        }
        return false;
    }
};
int main()
{
    // [23,2,4,6,7], k = 6   output: true
    vector<int> vec{0, 1, 0}; //{23, 2, 4, 6, 7};
    int k = -6;
    vector<int> vec2{3, 5, 2, -2, 4, 1};
    int k2 = 5;
    Solution slv;
    cout << boolalpha << slv.checkSubarraySum(vec, k) << noboolalpha << endl;
    Solution2 slv2;
    cout << boolalpha << slv2.checkSubarraySum(vec, k) << noboolalpha << endl;
    return 0;
}