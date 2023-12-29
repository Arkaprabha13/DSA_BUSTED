class Solution {
public:
    int helper(vector<int>& jobDifficulty, int n, int d, int start, vector<vector<int>>& memo) {
    if (d == 1) {
        int maxDifficulty = INT_MIN;
        for (int i = start; i < n; i++) {
            maxDifficulty = max(maxDifficulty, jobDifficulty[i]);
        }
        return maxDifficulty;
    }

    if (memo[d][start] != -1) {
        return memo[d][start];
    }

    int minDifficulty = INT_MAX;
    int maxDifficulty = INT_MIN;

    for (int i = start; i < n - d + 1; i++) {
        maxDifficulty = max(maxDifficulty, jobDifficulty[i]);
        int nextDifficulty = helper(jobDifficulty, n, d - 1, i + 1, memo);
        minDifficulty = min(minDifficulty, maxDifficulty + nextDifficulty);
    }

    memo[d][start] = minDifficulty;
    return minDifficulty;
}

int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();

    if (n < d) {
        return -1;  // Cannot schedule jobs in d days
    }

    vector<vector<int>> memo(d + 1, vector<int>(n, -1));

    return helper(jobDifficulty, n, d, 0, memo);
}

};
