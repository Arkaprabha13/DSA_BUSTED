#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void max_heapify(vector<int> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);

        max_heapify(a, n, largest);
    }
}
void build_heap(vector<int> &a, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        max_heapify(a, n, i);
    }
}
void heap_sort(vector<int> &arr)
{
    int n = arr.size();
    build_heap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        {
            max_heapify(arr, i, 0);
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
    heap_sort(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}