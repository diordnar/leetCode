#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 不满足时间复杂度 log(m+n)
class Solution1
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto len = nums1.size() + nums2.size();
        vector<int> res(len);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), res.begin());
        int mid = len / 2;
        double val = (len % 2 == 0) ? (res[mid] + res[mid - 1]) / 2.0 : res[mid];
        return val;
    }
};

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        return 0;
    }
};

int main()
{
    vector<int> v1{1, 3};
    vector<int> v2{2};
    vector<int> v3{1, 2};
    vector<int> v4{3, 4};
    // Solution1 slv;
    // cout << slv.findMedianSortedArrays(v1, v2) << endl;
    // cout << slv.findMedianSortedArrays(v3, v4) << endl;
    return 0;
}