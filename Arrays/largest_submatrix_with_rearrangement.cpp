class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>ones(matrix.size());
        for(int j=0;j<matrix[0].size();j++)
        {
            int dp=0;
            for(int i=0;i<matrix.size();i++)
            {
                if(matrix[i][j]==0)
                {
                    dp=0;
                }
                else
                {
                    ++dp;
                }
                ones[i].push_back(dp);
            }
        }
        int ans=0;
        for(int i=0;i<ones.size();i++)
        {
            sort(ones[i].begin(),ones[i].end(),greater<int>{});
            int row=0;
            for(int j=0;j<ones[i].size();j++)
            {
                row=max(row,ones[i][j]*(j+1));
            }
            ans=max(ans,row);            
        }
        return ans;
    }
};
