class Solution {
public:
    bool cansplit(vector<int>& nums, int k, int maxallowed){
        int parts = 1;
        long long currsum = 0;

        for(int num : nums){
            if(currsum + num > maxallowed){
                parts++;
                currsum = num;
            }else{
                currsum += num;
            }
        }
        return parts <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        int high = sum;

        while(low <= high){
            int mid= low + (high - low)/2;
            if(cansplit(nums, k, mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};