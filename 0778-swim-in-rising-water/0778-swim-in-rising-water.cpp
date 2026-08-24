class Solution {
public:
    bool bfs(vector<vector<int>>& a, int n, int m, int money){
        
        if(a[0][0] > money) return false;
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0; i< n;i++){
            vector<int> t(m,0);
            vis[i] = t;
        }
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            if(row == n-1 && col == m-1){
                return true;
            }
            for(int k = 0; k < 4; k++){
                int row = p.first + x[k];
                int col = p.second + y[k];
                if(row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && a[row][col] <= money){
                    q.push({row, col});
                    vis[row][col] = 1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        int low = max(a[0][0], a[n-1][m-1]);
        int high = a[0][0];

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                high = max(high, a[i][j]);
            }
        }
        int res = high;
        while(low <= high){
            int guess = low + (high - low)/2;
            if(bfs(a, n, m, guess)){
                res = guess;
                high = guess -1;
            }else{
                low = guess + 1;
            }
        }
        return res;
    }
};