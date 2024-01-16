#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> left_array(n1, 0);
    vector<int> right_array(n2, 0);

    for (int i = 0; i < n1; i++)
    {
        left_array[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right_array[j] = arr[mid + j + 1];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i++];
        }
        else
        {
            arr[k] = right_array[j++];
        }
        k++;
    }
    while (i < n1)
    {
        arr[k++] = left_array[i++];
    }
    while (j < n2)
    {
        arr[k++] = right_array[j++];
    }
}
void merge_sort(vector<int> &array, int low, int high)
{
    if(low < high)
    {
        int mid = low + (high - low) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);

        merge(array, low, mid, high);
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
    merge_sort(v, 0, n);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}