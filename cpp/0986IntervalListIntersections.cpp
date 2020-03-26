#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 986. 区间列表的交集
// 给定两个由一些闭区间组成的列表，每个区间列表都是成对不相交的，并且已经排序。
// 返回这两个区间列表的交集。
// （形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b。
// 两个闭区间的交集是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。）

// 示例：
// 输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
// 输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
// 注意：输入和所需的输出都是区间对象组成的列表，而不是数组或列表。

// 提示：
//     0 <= A.length < 1000
//     0 <= B.length < 1000
//     0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/interval-list-intersections
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> res;
        int len1 = A.size(), len2 = B.size();
        // if (len1 == 0 || len2 == 0)
        // {
        //     return res;
        // }

        for (int i = 0, j = 0; i < len1 && j < len2;)
        {
            int a1 = A[i][0];
            int a2 = A[i][1];
            int b1 = B[j][0];
            int b2 = B[j][1];
            if (a2 >= b1 && b2 >= a1)
            {
                auto c1 = max(a1, b1);
                auto c2 = min(a2, b2);
                res.push_back({c1, c2});
            }
            // b2 > a2 or b2 < a2 均可
            // if (b2 > a2)
            // {
            //     ++i;
            // }
            // else
            // {
            //     ++j;
            // }

            if (b2 < a2)
            {
                ++j;
            }
            else
            {
                ++i;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> A = {{0, 2}, {5, 10}, {13, 23}, {24, 25}},
                        B = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    Solution slv;
    auto ret = slv.intervalIntersection(A, B);
    return 0;
}