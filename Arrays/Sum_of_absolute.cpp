class Solution {
public:
    // vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>v;
    //     for(int i=0;i<n;i++)
    //     {
    //         int sum=0;
    //         for(int j=0;j<n;j++)
    //         {   
    //             sum+=abs(nums[i]-nums[j]);                
    //         }
    //         v.push_back(sum);
    //     }
    //     return v;
    // }this is getting tle
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);

    // Calculate the total sum of the array
    int total_sum = 0;
    for (int num : nums) {
        total_sum += num;
    }

    int prefix_sum = 0;
    int suffix_sum = total_sum;

    for (int i = 0; i < n; i++) {
        // Calculate the sum of absolute differences
        result[i] = nums[i] * i - prefix_sum + suffix_sum - nums[i] * (n - i);

        // Update the prefix sum and suffix sum
        prefix_sum += nums[i];
        suffix_sum -= nums[i];
    }

    return result;
}

};
