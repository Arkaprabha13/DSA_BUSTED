class Solution {
public: unordered_map<int, int> memo; // Memoization map

    int recursiveHelper(int index, const vector<pair<int, pair<int, int>>>& jobs) {
        if (index == 0) {
            return jobs[0].second.second;
        }

        // Check if the result for the current state is already memoized
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        int currProfit = jobs[index].second.second;
        int prevJobIndex = -1;

        // Find the latest non-overlapping job
        for (int j = index - 1; j >= 0; --j) {
            int jobStartTime = jobs[j].second.first; // Temporary variable
            if (jobs[j].first <= jobStartTime) {
                prevJobIndex = j;
                break;
            }
        }

        if (prevJobIndex != -1) {
            currProfit += recursiveHelper(prevJobIndex, jobs);
        }

        // Calculate the maximum profit for the current state and memoize the result
        int result = max(recursiveHelper(index - 1, jobs), currProfit);
        memo[index] = result;

        return result;
    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> jobs;

        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], {startTime[i], profit[i]}});
        }

        // Sort jobs by end time
        sort(jobs.begin(), jobs.end());

        return recursiveHelper(n - 1, jobs);
    }
};
