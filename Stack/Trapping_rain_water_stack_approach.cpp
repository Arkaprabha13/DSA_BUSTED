//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
     long long trappingWater(int a[], int n)
     {
         stack<int>s;
         long long ans=0;
         for(int i=0;i<n;i++)
         {
             while(!s.empty() && a[s.top()]<a[i])
             {
                 int current=s.top();
                 s.pop();
                 if(s.empty())
                 {
                     break;
                 }
                 else
                 {
                    long long dif=i-s.top()-1;
                    ans+=((min(a[s.top()],a[i])-a[current])*dif);
                 }  
             }
             s.push(i);
         }
         return ans;
     }

};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
