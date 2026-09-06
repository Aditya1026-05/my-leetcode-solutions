class Solution {
public:
    int mergesort(vector<int>& nums, int l, int r){
        if(l >= r) return 0;

        int mid = l + (r-l)/2;

        int count = 0;

        count += mergesort(nums, l, mid);
        count += mergesort(nums, mid+1, r);

        int j = mid + 1;

        for(int i = l; i <= mid; i++){
            while(j <= r && nums[i] > 2LL * nums[j]) j++;

            count += j - (mid+1);
        }

        vector<int> temp;

        int left = l;
        int right = mid +1;

        while(left <= mid && right <= r){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= r) temp.push_back(nums[right++]);

        for(int i = l; i<= r; i++){
            nums[i] = temp[i-l];
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size()-1);
    }
};