class Solution {
public:
    int searchin(vector<int>& nums, int target, int low, int high) {
        int n = nums.size();

        if(low > high) return -1;
        int mid = low + (high - low)/2;

        if(target < nums[mid]){
            return searchin(nums, target, low, mid-1);
        }else if(target > nums[mid]){
            return searchin(nums, target, mid + 1, high);
        }else{
            return mid;
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return searchin(nums, target, 0, n-1);
    }
};