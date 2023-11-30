/*
There are N buildings in Linear Land. They appear in a linear line one after the other and their heights are given in the array arr[]. 
Geek wants to select three buildings in Linear Land and remodel them as recreational spots.
The third of the selected building must be taller than the first and shorter than the second.
Can geek build the three-building recreational zone? 
*/
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
bool recreationalSpot(int arr[], int n){
		if(n<3) return false;
		int maxi = arr[1], mini = arr[0];
		for(int i=2; i<n; i++){
		    //Found 132
		    if(arr[i] > mini && arr[i] < maxi) return true;
		    
		    //Update maxi
		    maxi = max(maxi, arr[i]);
		    
		    //Update mini
		    if(arr[i-1]!=maxi) mini = min(mini, arr[i-1]);
		}
		return false;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}
// } Driver Code Ends
