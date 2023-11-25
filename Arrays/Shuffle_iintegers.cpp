//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
public:
void shuffleArray(int a[], int n) {
    int maxval = 1e4;

    // Shuffle the even indices (a2, a4, ...)
    for (int i = 2, j = 1; i < n; i += 2, j++) {
        a[i] = (a[j] % maxval) * maxval + a[i];
    }

    // Shuffle the odd indices (a1, a3, ...)
    for (int i = 1, j = n / 2; i < n; i += 2, j++) {
        a[i] = (a[j] % maxval) * maxval + a[i];
    }

    // Divide by maxval to get the shuffled values
    for (int i = 1; i < n; i++) {
        a[i] = a[i] / maxval;
    }
}

		 /*

Your code seems to be using a clever approach to achieve the shuffle without using extra space. It uses integer arithmetic and modular arithmetic to manipulate the array elements and store the shuffled values without using additional space. Here's an explanation of the code:

cpp
Copy code
void shuffleArray(int a[], int n) {
    int maxval = 1e4;

    // Shuffle the even indices (a2, a4, ...)
    for (int i = 2, j = 1; i < n; i += 2, j++) {
        a[i] = (a[j] % maxval) * maxval + a[i];
    }

    // Shuffle the odd indices (a1, a3, ...)
    for (int i = 1, j = n / 2; i < n; i += 2, j++) {
        a[i] = (a[j] % maxval) * maxval + a[i];
    }

    // Divide by maxval to get the shuffled values
    for (int i = 1; i < n; i++) {
        a[i] = a[i] / maxval;
    }
}
Explanation:

The first loop (even indices) takes values from the first half of the array (a1, a2, a3, ...) and 
stores them in the even indices (a2, a4, ...). It uses modular arithmetic to ensure that the values are within a specified range (maxval). 
The result is stored by multiplying with maxval and adding the original value.

The second loop (odd indices) takes values from the second half of the array (b1, b2, b3, ...) and 
stores them in the odd indices (a1, a3, ...). Similar to the first loop, it uses modular arithmetic and stores the result by multiplying with maxval and adding the original value.

The third loop divides the values by maxval to obtain the shuffled values.

This approach takes advantage of the fact that the array elements are integers and 
performs the shuffling without using extra space. However, it's essential to understand that this method relies on the assumption that
the maximum value (maxval) is large enough to prevent overlap between the original and shuffled values. If the array elements are constrained to a smaller range,
adjustments may be needed.
*/

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
