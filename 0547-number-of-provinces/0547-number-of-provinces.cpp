// class Solution {
// public:
//     void dfs(int i, vector<vector<int>>& adj, vector<bool> &vis){
//         vis[i] = true;
//         int n = vis.size();
//         for(int j = 0; j < n; j++){
//             if(adj[i][j] == 1 && !vis[j]) dfs(j, adj, vis);
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         vector<bool> vis(n, false);

//         int provinces = 0;

//         for(int i = 0; i < n ; i++){
//             if(!vis[i]){
//                 provinces++;
//                 dfs(i, isConnected, vis);
//             }
//         }
//         return provinces;
//     }
// };

class Solution {
public:

    vector<int> par;
    vector<int > rank;

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool unionset(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;

        if( rank[pa] < rank[pb]){
            par[pa] = pb;
        }else if( rank[pa] > rank[pb]){
            par[pb] = pa;
        }else{
            par[pb] = pa;
            rank[pa]++;
        }
        return true;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        par.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++){
            par[i] = i;
        }

        int provinces = n;

        for(int i = 0; i < n ; i++){
            for(int j = i + 1; j < n; j++){
                if(isConnected[i][j] == 1){
                    if(unionset(i,j)) provinces--;
                }
            }}
        return provinces;
    }
};