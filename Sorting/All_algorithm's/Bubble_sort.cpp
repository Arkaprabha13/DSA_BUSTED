#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bubble_sort(vector<int> &array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}
void optimised_bubble_sort(vector<int> &array, int n)
{
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        // If no swapping occurred, the array is already sorted
        if (!swapped)
        {
            break;
        }
    }
}
int main()
{
    vector<int> v;
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // bubble_sort(v, n);
    optimised_bubble_sort(v, n);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}