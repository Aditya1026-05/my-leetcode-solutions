class Solution {
public:
    bool possible(vector<int>& nums, int threshold, int d){
        long long sum = 0;

        for(int num : nums){
            sum += (num + d - 1)/d;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low+ (high - low)/2;
            if(possible(nums, threshold, mid)){
                
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};