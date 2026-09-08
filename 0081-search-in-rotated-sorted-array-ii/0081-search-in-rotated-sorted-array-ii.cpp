class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int low = 0;
        int high = nums.size() - 1;
        while(low<= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == tar) return true;

            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                high--;
                low++;
                continue;
            }

            if(nums[low] <= nums[mid]){
                if(tar >= nums[low] && tar < nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(tar > nums[mid] && tar <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};