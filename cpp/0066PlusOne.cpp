// 66. 加一
// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。
// 示例 1:
// 输入: [1,2,3]
// 输出: [1,2,4]
// 解释: 输入数组表示数字 123。

// 示例 2:
// 输入: [4,3,2,1]
// 输出: [4,3,2,2]
// 解释: 输入数组表示数字 4321。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/plus-one
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        vector<int> res;
        stack<int> stk;
        stack<int> stkCal;
        for (auto &i : digits)
        {
            stk.push(i);
        }
        while (!stk.empty())
        {
            int num = stk.top() + carry;
            stk.pop();
            carry = num / 10;
            num %= 10;
            stkCal.push(num);
        }
        if (carry)
        {
            stkCal.push(carry);
        }
        while (!stkCal.empty())
        {
            res.push_back(stkCal.top());
            stkCal.pop();
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int len = digits.size();
        for (int i = len - 1; i >= 0; --i)
        {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0)
            {
                return digits;
            }
        }
        vector<int> res(len + 1, 0);
        res[0] = 1;
        return res;
    }
};

int main()
{
    return 0;
}
