//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;//pair<pair<row,col>,time>
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;                    
                }
            }
        }
        int time=0;
        int traversal_row[]={-1,0,1,0};
        int traversal_col[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(t,time);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int neighbour_row = r + traversal_row[i];
                int neighbour_col = c + traversal_col[i];
                if(neighbour_row>=0 && neighbour_row<n && neighbour_col>=0 && neighbour_col<m && vis[neighbour_row][neighbour_col]==0 && grid[neighbour_row][neighbour_col]==1)
            {
                q.push({{neighbour_row,neighbour_col},t+1});
                vis[neighbour_row][neighbour_col]=2;
            }
            }

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=2 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return time;
    
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
