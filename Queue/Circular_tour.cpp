//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int deficit = 0;  // Initialize a variable to keep track of deficit in petrol.
        int balance = 0;  // Initialize a variable to keep track of the current balance.
        int start = 0;    // Initialize the starting point as 0.

        for (int i = 0; i < n; i++) {
            // Update the balance by adding the difference between petrol and distance at the current pump.
            balance += p[i].petrol - p[i].distance;

            if (balance < 0) {
                // If the balance becomes negative, it means we can't start from the current point,
                // so we update the deficit and set the new starting point to the next pump.
                deficit += balance;
                start = i + 1;
                balance = 0;  // Reset the balance to zero.
            }
        }

        if (deficit + balance >= 0) {
            // If the total deficit and the final balance are non-negative,
            // it means there's a solution, and we can return the starting point.
            return start;
        } else {
            // If there's no solution, return -1.
            return -1;
        }
    
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
