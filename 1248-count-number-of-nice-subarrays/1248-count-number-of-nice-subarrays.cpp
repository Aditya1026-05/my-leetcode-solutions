class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        if(k<0) return 0;
        int left = 0;
        long long ans = 0;
        int oddcount = 0;

        for(int right = 0; right < nums.size(); right++){
            oddcount += nums[right] % 2;

            while(oddcount > k){
                oddcount -= nums[left]%2;
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};