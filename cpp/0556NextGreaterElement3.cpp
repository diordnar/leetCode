#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 556. 下一个更大元素 III
// 给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。
// 如果不存在这样的32位整数，则返回-1。

// 示例 1:
// 输入: 12
// 输出: 21

// 示例 2:
// 输入: 21
// 输出: -1

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/next-greater-element-iii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        vector<int> vec;
        int base = 1;
        int tmp = n;
        while (tmp >= 10)
        {
            tmp /= 10;
            base *= 10;
        }
        tmp = n;
        while (base > 0)
        {
            vec.push_back(tmp / base);
            tmp %= base;
            base /= 10;
        }

        long ret = 0;
        if (next_permutation(vec.begin(), vec.end()))
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                ret = ret * 10 + vec[i];
            }
            if (ret > INT_MAX || ret < INT_MIN)
            {
                return -1;
            }
            return ret;
        }
        return -1;
    }
};

class Solution2
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        if (next_permutation(s.begin(), s.end()))
        {
            long long r = stoll(s);
            if (r > INT_MAX || r < INT_MIN)
                return -1;
            else
                return r;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int num1 = 12, num2 = 21;
    Solution slv;
    cout << slv.nextGreaterElement(num1) << endl;
    cout << slv.nextGreaterElement(num2) << endl;
    return 0;
}