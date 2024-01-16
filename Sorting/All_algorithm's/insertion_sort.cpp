#include <bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int> &array, int n)
{
    for(int i=1;i<n;i++)
    {
        int key=array[i];
        int j=i-1;
        while(j>=0 && array[j]>key)// using >= in 2nd case make algo unstable
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
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
    insertion_sort(v, n);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}