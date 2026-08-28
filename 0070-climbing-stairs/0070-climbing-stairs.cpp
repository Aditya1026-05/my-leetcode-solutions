class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        if(dp.empty())
        dp.resize(n+1, -1);
        if(n==1 || n ==2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climbStairs(n-1) + climbStairs(n-2); 
    }
};