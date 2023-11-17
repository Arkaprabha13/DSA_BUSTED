class Solution {
public:
    int f(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int current_sum = 0;
        int i = index;
        while (i < nums.size() && nums[i] == nums[index]) {
            current_sum += nums[i];
            i++;
        }
        while (i < nums.size() && nums[i] == nums[index] + 1) {
            i++;
        }
        return dp[index] = max(current_sum + f(nums, i, dp), f(nums, index + 1, dp));
    }

    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        sort(nums.begin(), nums.end());
        return f(nums, 0, dp);
    }
};
