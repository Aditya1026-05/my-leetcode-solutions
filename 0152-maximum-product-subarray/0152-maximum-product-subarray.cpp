// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int prevMax = nums[0];
//         int prevMin = nums[0];
//         int ans = nums[0];

//         for(int i = 1; i<n; i++){
            
//             int oldmax = prevMax;
//             int oldmin = prevMin;
            
//             prevMax = max({nums[i], oldmin * nums[i], oldmax * nums[i]});
//             prevMin = min({nums[i], oldmax * nums[i], oldmin * nums[i]});

//             ans = max(ans,prevMax);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n ; i++){
            if(nums[i] < 0) swap(currMin, currMax);

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            ans = max(ans, currMax);
        }
        return ans;
    }
};