#include <bits/stdc++.h>
using namespace std;
int max_even_odd(int *a, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        int current = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((a[j] % 2 == 0 && a[j - 1] % 2 != 0) || (a[j] % 2 != 0 && a[j - 1] % 2 == 0))
            {
                current++;
            }
            else
            {
                break;
            }
        }
        result = max(result, current);
    }
    return result;
}
int efficient_solution(int *a, int n)
{
    int result = 1;
    int current = 1;
    for (int j = 1; j < n; j++)
    {
        if ((a[j] % 2 == 0 && a[j - 1] % 2 != 0) || (a[j] % 2 != 0 && a[j - 1] % 2 == 0))
        {
            current++;
            result=max(result,current);
        }
        else
        {
            current = 1;
        }
    }
    return result;
}
int main()
{
    int n;
    cout << "N-> ";
    cin >> n;
    cout << endl;
    int *arr = new int[n]; // Allocate memory for the array

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << efficient_solution(arr, n) << endl;
    return 0;
}
