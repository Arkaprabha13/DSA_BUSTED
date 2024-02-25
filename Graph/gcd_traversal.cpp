class Solution {
public:
 void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }
    
    void allprime(int n, unordered_map<int, vector<int>>& map, int st) {
        while (n % 2 == 0) {
            map[2].push_back(st);
            n /= 2;
        }
        for (int i = 3; i <= sqrt(n); i += 2) {
            while (n % i == 0) {
                map[i].push_back(st);
                n /= i;
            }
        }
        if (n > 2) {
            map[n].push_back(st);
        }
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        unordered_map<int, vector<int>> map;
        
        for (int i = 0; i < n; ++i) {
            allprime(nums[i], map, i);
        }
        
        for (auto& p : map) {
            for (int i = 1; i < p.second.size(); ++i) {
                graph[p.second[i - 1]].push_back(p.second[i]);
                graph[p.second[i]].push_back(p.second[i - 1]);
            }
        }
        
        vector<bool> visited(n, false);
        dfs(graph, visited, 0);
        
        for (bool v : visited) {
            if (!v) return false;
        }
        
        return true;
    }
};
