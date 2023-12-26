#include <bits/stdc++.h>
using namespace std;
void efficient_transpose(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
}
void transpose(int **mat, int n)
{
    int temp[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = mat[j][i];

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         mat[i][j] = temp[i][j];
}
int main()
{
    int n;
    cout << "N-> ";
    cin >> n;
    int **arr;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            // cout << arr100[i][j] << " ";
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
    cout << "\ntranspose -> \n";
    transpose(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
    cout << "\nefficient transpose -> \n";
    efficient_transpose(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}
