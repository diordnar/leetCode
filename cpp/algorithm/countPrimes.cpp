#include <iostream>
#include <vector>

using namespace std;
// 返回区间 [2, n) 中有几个素数
int countPrimes(int n)
{
    vector<bool> isPrime(n, true);
    for (int i = 2; i * i < n; ++i)
    {
        for (int j = i * i; j < n; j += i)
        {
            isPrime[j] = false;
        }
    }
    int ret = 0;
    for (int i = 2; i < n; ++i)
    {
        if (isPrime[i])
        {
            ++ret;
            if (ret % 10 == 0)
            {
                cout << endl;
            }
            cout << i << " ";
        }
    }
    cout << endl;
    return ret;
}

int main()
{
    cout << countPrimes(10000) << endl;
    return 0;
}