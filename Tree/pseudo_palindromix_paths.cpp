class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        return dfs(root, vector<int>(10, 0));
    }

    int dfs(TreeNode* node, vector<int> count) {
        if (!node) {
            return 0;
        }

        count[node->val]++;
        if (!node->left && !node->right) {
            // Check if the current path is pseudo-palindromic
            int oddCount = countOddDigits(count);
            count[node->val]--;  // Backtrack
            return (oddCount <= 1) ? 1 : 0;
        }

        int leftCount = dfs(node->left, count);
        int rightCount = dfs(node->right, count);

        count[node->val]--;  // Backtrack

        return leftCount + rightCount;
    }

    int countOddDigits(const vector<int>& count) {
        return count_if(count.begin(), count.end(), [](int c) { return c % 2 == 1; });
    }
};
