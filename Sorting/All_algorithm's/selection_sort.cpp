#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void selection_sort(vector<int> &array, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        swap(array[min_index], array[i]);
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

    selection_sort(v, n);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}