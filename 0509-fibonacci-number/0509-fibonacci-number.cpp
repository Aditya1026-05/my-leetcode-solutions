class Solution {
public:
    vector<int> dp;
    int fib(int n) {
        dp.resize(n+1,-1);
        if(n == 0 || n == 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1) + fib(n-2); 
    }
};