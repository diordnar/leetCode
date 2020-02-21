#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> umap;
        int minus;
        for (auto i = 0; i < nums.size(); ++i)
        {
            minus = target - nums[i];
            if (umap.find(minus) != umap.end())
            {
                vector<int> ret{umap[minus], i};
                return ret;
                // int ret[] = {umap[minus], i};
                // return vector<int>(ret, ret + 2);
            }
            umap[nums[i]] = i;
        }

        return vector<int>{-1, -1};
    }
};

int main()
{
    vector<int> vec{2, 7, 11, 15};
    int tg = 9;
    Solution solution;
    vector<int> result = solution.twoSum(vec, tg);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    return 0;
}