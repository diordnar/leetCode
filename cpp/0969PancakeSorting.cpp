#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 969. 煎饼排序
// 给定数组 A，我们可以对其进行煎饼翻转：我们选择一些正整数 k <= A.length，然后反转 A 的前 k
// 个元素的顺序。我们要执行零次或多次煎饼翻转（按顺序一次接一次地进行）以完成对数组 A 的排序。
// 返回能使 A 排序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * A.length
// 范围内的有效答案都将被判断为正确。

// 示例 1：
// 输入：[3,2,4,1]
// 输出：[4,2,4,3]
// 解释：
// 我们执行 4 次煎饼翻转，k 值分别为 4，2，4，和 3。
// 初始状态 A = [3, 2, 4, 1]
// 第一次翻转后 (k=4): A = [1, 4, 2, 3]
// 第二次翻转后 (k=2): A = [4, 1, 2, 3]
// 第三次翻转后 (k=4): A = [3, 2, 1, 4]
// 第四次翻转后 (k=3): A = [1, 2, 3, 4]，此时已完成排序。

// 示例 2：
// 输入：[1,2,3]
// 输出：[]
// 解释：
// 输入已经排序，因此不需要翻转任何内容。
// 请注意，其他可能的答案，如[3，3]，也将被接受。

// 提示：
//     1 <= A.length <= 100
//     A[i] 是 [1, 2, ..., A.length] 的排列

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/pancake-sorting
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &A)
    {
        vector<int> res;

        int srtcnt = 0;
        int sz = A.size();
        for (int i = 0; i < sz; ++i)
        {
            int max = INT_MIN;
            int idx = 0;
            for (int j = 0; j < sz - srtcnt; ++j)
            {

                if (A[j] > max)
                {
                    max = A[j];
                    idx = j;
                }
            }

            if (idx == 0)
            {
                res.push_back(sz - srtcnt);
                reverse(A.begin(), A.begin() + sz - srtcnt);
            }
            else
            {
                res.push_back(idx + 1);
                reverse(A.begin(), A.begin() + idx + 1);
                res.push_back(sz - srtcnt);
                reverse(A.begin(), A.begin() + sz - srtcnt);
            }

            ++srtcnt;
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> pancakeSort(vector<int> &A)
    {
        sort(A, A.size());
        return res;
    }

private:
    void sort(vector<int> &v, int n)
    {
        if (n == 1)
        {
            return;
        }
        int max = 0;
        int idx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] > max)
            {
                max = v[i];
                idx = i;
            }
        }

        res.push_back(idx + 1);
        reverseN(v, 0, idx);
        res.push_back(n);
        reverseN(v, 0, n - 1);

        sort(v, n - 1);
    }

    void reverseN(vector<int> &v, int i, int j)
    {
        while (i < j)
        {
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            ++i;
            --j;
        }
    }

private:
    vector<int> res;
};

class Solution3
{
public:
    vector<int> pancakeSort(vector<int> &A)
    {
        vector<int> V;
        int temp = 0; //每一次循环最大的元素一定在正确位置，所以使用temp来缩短遍历长度
        for (int j = 0; j < A.size(); j++)
        {
            int max = -1, index = 0;
            for (int i = 0; i < A.size() - temp; i++) //寻找剩余元素中的最大值，返回其下标
            {
                if (max < A[i])
                {
                    max = A[i];
                    index = i;
                }
            }
            if (index == 0) //如果最大值恰好在第一个元素位置，那么直接进行翻转A.size() - temp长度将其转到剩余元素的最大位置
            {
                V.push_back(A.size() - temp);
                reverseK(A, A.size() - temp);
            }
            else
            {
                V.push_back(index + 1); //先将其翻转到第一个元素位置
                reverseK(A, index + 1);
                V.push_back(A.size() - temp); //再将第一个元素位置翻转到剩余元素最大值位置
                reverseK(A, A.size() - temp);
            }
            temp++;
        }
        return V;
    }

private:
    void reverseK(vector<int> &V, int k) //翻转vector的前k个元素
    {
        if (k > V.size())
        {
            return;
        }
        reverse(V.begin(), V.begin() + k);
    }
};

int main()
{
    vector<int> vec1{3, 2, 4, 1};
    vector<int> vec2{9, 8, 7, 6, 5, 4, 3, 2, 1};
    Solution2 slv;
    vector<int> ret = slv.pancakeSort(vec1);
    for (auto i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}