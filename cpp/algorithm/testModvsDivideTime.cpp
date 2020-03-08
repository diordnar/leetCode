#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
    const unsigned CNT = 4000000000;
    //clock_t start1 = clock();
    auto start1 = chrono::steady_clock::now();
    for (unsigned i = 0; i < CNT; ++i)
    {
        unsigned tmp = i % 10;
    }
    auto end1 = chrono::steady_clock::now();
    auto p1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1);
    // auto end1 = clock();
    // auto p1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Mod: " << p1.count() << " ms" << endl;

    // clock_t start2 = clock();
    auto start2 = chrono::steady_clock::now();
    for (unsigned i = 0; i < CNT; ++i)
    {
        unsigned tmp = i - (i / 10) * 10;
    }
    auto end2 = chrono::steady_clock::now();
    auto p2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
    // auto end2 = clock();
    // auto p2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Mod: " << p2.count() << " ms" << endl;
    return 0;
}