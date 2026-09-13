class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int missing = arr[mid] - (mid+1);

            if(missing >= k){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low+k;
    }
};

//Brute Force

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         vector<int> ans;
//         int high = *max_element(arr.begin(), arr.end())+k;

//         unordered_map<int, int> mp;

//         for(int i = 0; i < arr.size(); i++){
//             mp[arr[i]]++;
//         }

//         for(int i = 1; i <= high; i++){
//             if(mp.find(i) == mp.end()){
//                 ans.push_back(i);
//             }
//         }
//         return ans[k-1];
//     }
// };