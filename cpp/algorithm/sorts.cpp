#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static void quickSort(vector<int> &vec, int start, int end)
    {
        if (start > end)
            return;

        int i = start, j = end, tmp;
        int base = vec[i];
        while (i != j)
        {
            while (vec[j] >= base && i < j)
                --j;
            while (vec[i] <= base && i < j)
                ++i;
            if (i < j)
            {
                tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
                //swap(vec[i],vec[j]);
            }
        }
        vec[start] = vec[i];
        vec[i] = base;

        quickSort(vec, start, i - 1);
        quickSort(vec, i + 1, end);
    }

    static void bubbleSort(vector<int> &vec)
    {
        int tmp;
        int sz = vec.size();
        for (int i = 0; i < sz - 1; ++i)
        {
            for (int j = 0; j < sz - 1 - i; ++j)
            {
                if (vec[j] > vec[j + 1])
                {
                    tmp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = tmp;
                }
            }
        }
    }
    static void insertionSort(vector<int> &vec)
    {
        int len = vec.size();
        for (int i = 1; i < len; ++i)
        {
            int j = i - 1;
            int tmp = vec[i];
            while (j >= 0 && tmp < vec[j])
            {
                vec[j + 1] = vec[j];
                --j;
            }
            vec[j + 1] = tmp;
        }
    }
    static void selectionSort(vector<int> &vec)
    {
        int len = vec.size();
        for (int i = 0; i < len - 1; ++i)
        {
            int min_idx = i;
            for (int j = i + 1; j < len; ++j)
            {
                if (vec[j] < vec[i])
                {
                    min_idx = j;
                }
            }
            swap(vec[i], vec[min_idx]);
        }
    }
};

int main()
{
    vector<int> vec{9, 8, 5, 1, 7, 6};
    cout << "Before sort:" << endl;
    for (auto &elm : vec)
    {
        cout << elm << " ";
    }
    cout << endl;
    //Solution::quickSort(vec, 0, vec.size() - 1);
    //Solution::bubbleSort(vec);
    //Solution::insertionSort(vec);
    Solution::selectionSort(vec);
    cout << "After sort:" << endl;
    for (auto &elm : vec)
    {
        cout << elm << " ";
    }
    cout << endl;
    return 0;
}