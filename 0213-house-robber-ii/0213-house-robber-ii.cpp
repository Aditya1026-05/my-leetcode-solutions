class Solution {
public:
    int robLinear(vector<int>& nums, int start,int end) {
        int n = nums.size();

        if(start == end) return nums[start];

        int prev1 = nums[start];
        int prev2 = max(nums[start],nums[start+1]);
        int result = prev2;

        for(int i = start + 2; i <= end ; i++){
            result = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2  = result;
        }
        return result;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int case1 = robLinear(nums, 0,n-2);
        int case2 = robLinear(nums, 1,n-1);

        return max(case1, case2);
    }
};