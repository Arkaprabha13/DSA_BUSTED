#include <bits/stdc++.h>
using namespace std;
int get_max(vector<int> a)
{
    int maxi = INT_MIN;
    for (auto i : a)
    {
        if (maxi < i)
        {
            maxi = i;
        }
    }
    return maxi;
}
void counting_Sort(vector<int> &array)
{
    int max_element = get_max(array);
    vector<int> count_array(max_element + 1, 0);
    for (int i : array)
    {
        count_array[i]++;
    }
    for (int i = 1; i <= max_element; i++)
    {
        count_array[i] += count_array[i - 1];
    }
    vector<int> result(array.size());
    for (int i = array.size() - 1; i >= 0; i--)
    {
        result[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    for (size_t i = 0; i < array.size(); i++)
    {
        array[i] = result[i];
    }
}
int main()
{
    vector<int> arr = {4, 2, 10, 8, 3, 1, 7, 9, 5, 6};

    cout << "Original array: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    counting_Sort(arr);

    cout << "Sorted array: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}