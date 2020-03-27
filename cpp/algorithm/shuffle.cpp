#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

void shuffle(vector<int> &arr)
{
    int len = arr.size();
    random_device rd;
    default_random_engine eng(rd());
    for (int i = 0; i < len; ++i)
    {
        uniform_int_distribution<> d(i, len - 1);
        int rand = d(eng);
        swap(arr[rand], arr[i]);
    }
}

int main()
{
    const int N = 1000000;
    // 蒙特卡罗法验证
    vector<int> vec{1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int LEN = vec.size();
    vector<int> cnts(LEN);
    for (int i = 0; i < N; ++i)
    {
        shuffle(vec);
        for (int j = 0; j < LEN; ++j)
        {
            if (vec[j] == 1)
            {
                ++cnts[j];
            }
        }
    }
    for (auto i : cnts)
    {
        cout << static_cast<double>(i) / N << endl;
    }

    return 0;
}
