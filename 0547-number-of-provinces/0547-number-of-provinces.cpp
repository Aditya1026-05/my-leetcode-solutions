class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool> &vis){
        vis[i] = true;
        int n = vis.size();
        for(int j = 0; j < n; j++){
            if(adj[i][j] == 1 && !vis[j]) dfs(j, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);

        int provinces = 0;

        for(int i = 0; i < n ; i++){
            if(!vis[i]){
                provinces++;
                dfs(i, isConnected, vis);
            }
        }
        return provinces;
    }
};