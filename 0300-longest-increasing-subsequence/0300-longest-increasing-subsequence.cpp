// Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < i ; j++){
                if(nums[j] < nums[i]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
};


//Memoization
// class Solution {
// public:
//     vector<vector<int>> dp;
//     int solve(int i, int prev, vector<int>& nums){
//         if(i == nums.size()) return 0;

//         if(dp[i][prev+1] != -1) return dp[i][prev+1];

//         int exclude = solve(i+1, prev, nums);
//         int include = 0;

//         if(prev == -1 || nums[i] > nums[prev]){
//             include = 1 + solve(i+1, i, nums);
//         }
//         return dp[i][prev+1] = max(include, exclude);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         dp.resize(n, vector<int>(n+1,-1));
//         return solve(0, -1, nums);
//     }
// };



//Brute Force


// class Solution {
// public:
//     int solve(int i, int prev, vector<int>& nums){
//         if(i == nums.size()) return 0;

//         int exclude = solve(i+1, prev, nums);
//         int include = 0;

//         if(prev == -1 || nums[i] > nums[prev]){
//             include = 1 + solve(i+1, i, nums);
//         }
//         return max(include, exclude);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         return solve(0, -1, nums);
//     }
// };