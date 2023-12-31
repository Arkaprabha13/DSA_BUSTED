// Define constants for modulo and the maximum size of the array
const int MOD = 1e9 + 7;
const int N = 3010;

// Arrays to store factorials and their inverses
long f[N];
long g[N];

// Helper function for fast exponentiation
long qmi(long a, int k) {
    long res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res = res * a % MOD;
        }
        k >>= 1;
        a = a * a % MOD;
    }
    return res;
}

// Initialization lambda function for precomputing factorials and inverses
int init = []() {
    // Initialize base cases for 0!
    f[0] = g[0] = 1;

    // Loop to compute factorials and their inverses
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;     // Compute factorial
        g[i] = qmi(f[i], MOD - 2);     // Compute inverse of factorial using fast exponentiation
    }

    // The lambda function returns 0
    return 0;
}();

// Definition of the Solution class
class Solution {
public:
    // Function to calculate the number of operations to make the string sorted
    int makeStringSorted(string s) {
        // Array to count occurrences of each character
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        
        // Length of the string
        int n = s.size();
        
        // Variable to store the total number of operations
        long ans = 0;
        
        // Iterate through each character in the string
        for (int i = 0; i < n; ++i) {
            // Count the number of characters smaller than the current character
            int m = 0;
            for (int j = 0; j < 26; ++j) {
                if (j < s[i] - 'a') {
                    m += cnt[j];
                }
            }

            // Calculate the contribution of the current character using combinatorial logic
            long t = m * f[n - i - 1] % MOD;
            for (int j = 0; j < 26; ++j) {
                t = t * g[cnt[j]] % MOD;
            }

            // Update the total count
            ans = (ans + t) % MOD;

            // Decrease the count of the current character
            --cnt[s[i] - 'a'];
        }

        // Return the final result
        return ans;
    }
};
