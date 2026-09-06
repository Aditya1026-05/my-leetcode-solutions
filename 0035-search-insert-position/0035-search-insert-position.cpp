class Solution {
public:
    int searchInsert(vector<int>& A, int tar) {
        int n = A.size();
        int low = 0; int high = n-1;
        int ans = A.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            if(A[mid] >= tar){
                ans = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};