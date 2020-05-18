#include <vector>
#include <string>
#include <iostream>
using namespace std;

// 14. 最长公共前缀
// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。
// 示例 1:
// 输入: ["flower","flow","flight"]
// 输出: "fl"

// 示例 2:
// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-common-prefix
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int sz = strs.size();
        if (sz == 0)
        {
            return "";
        }

        string res = strs[0];
        for (int i = 1; i < sz; ++i)
        {
            auto s = strs[i];
            int idx = 0;
            for (; idx < res.length() && idx < s.length(); ++idx)
            {
                if (res[idx] != s[idx])
                {
                    break;
                }
            }
            res = res.substr(0, idx);
            if (res.empty())
            {
                return res;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}