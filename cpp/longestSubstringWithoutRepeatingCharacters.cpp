#include <unordered_map>
#include <string>
#include <algorithm> // max
#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int start = 0, end = 0, length = 0, result = 0;
        unordered_map<char, int> umap;
        auto sz = s.size();
        while (end < sz)
        {
            char c = s[end];
            if (umap.find(c) != umap.end() && start <= umap[c])
            {
                start = umap[c] + 1;
                length = end - start;
            }
            umap[c] = end;
            ++end;
            ++length;
            result = max(result, length);
        }
        return result;
    }
};

int main()
{
    Solution slv;
    string str = "abcabcbb";
    cout << slv.lengthOfLongestSubstring(str) << endl;
    return 0;
}