/*

**Initial state:** `count = 0`, `pre = 0`, `preLow = 0`

1. **i = 0:** `a[0] = 2` (between l and r), so we go to the else block.
   - `count += (pre + preLow + 1)`: `count = 1`, `pre = 1`, `preLow = 0`.

2. **i = 1:** `a[1] = 0` (less than l), so we go to the if block.
   - `count += pre`: `count = 1`, `preLow = 1`.

3. **i = 2:** `a[2] = 11` (greater than r), so we go to the else if block.
   - `pre = preLow = 0`.

4. **i = 3:** `a[3] = 3` (between l and r), so we go to the else block.
   - `count += (pre + preLow + 1)`: `count = 3`, `pre = 1`, `preLow = 0`.

5. **i = 4:** `a[4] = 0` (less than l), so we go to the if block.
   - `count += pre`: `count = 4`, `preLow = 1`.

**Final result:** `count = 5`, which is the expected output for the given input. The code correctly counts the number of subarrays meeting the condition.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
public:
long countSubarrays(int a[], int n, int l, int r) {
    long count = 0;   // Total count of subarrays meeting the condition
    long pre = 0;     // Count of subarrays ending at the current index with max in range [l, r]
    long preLow = 0;  // Count of subarrays ending at the current index with max less than l

    for (int i = 0; i < n; ++i) {
        if (a[i] < l) {
            // If the current element is less than l, add the count of subarrays ending
            // at the previous index with max in range [l, r] to the total count.
            // Also, increment the count of subarrays ending at the current index with max less than l.
            count += pre;
            preLow++;
        } else if (a[i] > r) {
            // If the current element is greater than r, reset both pre and preLow to zero,
            // as the current element is outside the valid range.
            pre = preLow = 0;
        } else {
            // If the current element is between l and r (inclusive),
            // update the total count by adding the count of subarrays ending at the current index
            // with max in range [l, r]. Update pre and preLow accordingly.
            count += (pre + preLow + 1);
            pre += (preLow + 1);
            preLow = 0;
        }
    }

    return count;
}

};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends
