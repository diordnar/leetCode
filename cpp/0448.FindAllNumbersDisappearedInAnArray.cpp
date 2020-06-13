// 448. 找到所有数组中消失的数字
// 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
// 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
// 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
// 示例:
// 输入:
// [4,3,2,7,8,2,3,1]
// 输出:
// [5,6]
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> res;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i)
        {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0)
            {
                nums[idx] *= -1;
            }
        }
        for (int i = 0; i < sz; ++i)
        {
            if (nums[i] > 0)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        unordered_map<int, bool> hashMap;
        vector<int> res;

        for (auto i : nums)
        {
            hashMap[i] = true;
        }
        int sz = nums.size();
        for (int i = 1; i <= sz; ++i)
        {
            if (!hashMap.count(i))
            {
                res.push_back(i);
            }
            // if (hashMap.find(i) == hashMap.end())
            // {
            //     res.push_back(i);
            // }
        }
        return res;
    }
};

int main()
{
    return 0;
}