class Solution {
public:
    bool possible(vector<int>& weights, int days, int cap){
        int daysused = 1;
        int currload = 0;

        for(int w : weights){
            if(currload +w > cap){
                daysused++;
                currload = w;
            }else{
                currload += w;
            }
        }

        return daysused <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for(int weight : weights){
            sum += weight;
        }
        int high = sum;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(possible(weights, days, mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};