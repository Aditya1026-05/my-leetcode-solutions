class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i == prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy){
            int buytoday = solve(i+1, 0, prices, dp) - prices[i];

            int skip = solve(i+1, 1, prices, dp);

            return dp[i][buy] = max(buytoday, skip);
        }else{
            int selltoday = solve(i+1, 1, prices, dp) + prices[i];

            int hold = solve(i+1, 0, prices, dp);

            return dp[i][buy] = max(selltoday, hold);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2,-1));

        return solve(0,1,prices,dp);
    }
};