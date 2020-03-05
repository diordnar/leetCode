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
                length = end - start; // length if条件外 +1
            }
            umap[c] = end;
            ++end;
            ++length;
            result = max(result, length);
        }
        return result;
    }
};

class Solution2
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, result = 0;
        unordered_map<char, int> window;
        while (right < s.size())
        {
            char c1 = s[right];
            ++window[c1];
            ++right;

            while (window[c1] > 1)
            {
                char c2 = s[left];
                --window[c2];
                ++left;
            }
            // 计算长度时right多加了1, left + 1跳过重复字符
            result = max(result, right - left);
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