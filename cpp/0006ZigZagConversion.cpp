#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        int slen = s.length();
        vector<string> vec(min(numRows, slen));
        bool is_down = false;
        int curr_row = 0;
        for (char c : s)
        {
            vec[curr_row] += c;
            if (curr_row == 0 || curr_row == numRows - 1)
            {
                is_down = !is_down;
            }
            curr_row += is_down ? 1 : -1;
        }

        string ret;
        for (auto &s : vec)
        {
            ret += s;
        }
        return ret;
    }
};

int main()
{
    string s("LEETCODEISHIRING");
    Solution slv;
    cout << slv.convert(s, 3) << endl;
    return 0;
}