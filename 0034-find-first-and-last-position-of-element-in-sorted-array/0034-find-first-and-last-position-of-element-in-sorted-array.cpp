class Solution {
public:
    int firstoccur(vector<int>& nums, int tar) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == tar){
                ans = mid;
                high = mid -1;
            }else if(nums[mid] < tar){
                low = mid + 1;
            }else{
                high = mid - 1;
                }
        }
        return ans;
    }
    
    int lastoccur(vector<int>& nums, int tar) {
        int low = 0;
        int high = nums.size() - 1;  

        int ans = -1; 

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == tar){
                ans = mid;
                low = mid + 1;
            }else if(nums[mid] < tar){
                low = mid + 1;
            }else{
                high = mid - 1;
                }
        }
        return ans;  
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstoccur(nums,target),lastoccur(nums, target)};
    }
};