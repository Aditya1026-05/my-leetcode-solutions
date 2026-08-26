class Solution {
public:
    int mandist(vector<vector<int>>& points, int p1, int p2){
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        int n = points.size();
        vector<bool> mstset(n, false);
        int mstcost = 0;

        pq.push({0,0});

        while(pq.size() > 0){
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;

            if(mstset[node]) continue;

            mstset[node] = true;
            mstcost += wt;

            for(int i = 0; i < n; i++){
                if(!mstset[i]){
                    int dist = mandist(points, node, i);
                    pq.push({dist, i});
                }
            }
        }
        return mstcost;
    }
};