class Solution {
public:
    bool canmake(vector<int>& bloomday, int day, int m, int k){
        int bouq = 0;
        int flowers = 0;

        for(int i = 0 ; i < bloomday.size(); i++){
            if(bloomday[i] <= day){
                flowers++;
            }else{
                flowers = 0;
            }

            if(flowers == k){
                bouq++;
                flowers = 0;
            }
        }
        return bouq >= m;
    }
    int minDays(vector<int>& bloomday, int m, int k) {
        if((long long)bloomday.size() < (long long)m * k) return -1;

        int low = *min_element(bloomday.begin(), bloomday.end());
        int high = *max_element(bloomday.begin(), bloomday.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if(canmake(bloomday, mid, m, k)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};