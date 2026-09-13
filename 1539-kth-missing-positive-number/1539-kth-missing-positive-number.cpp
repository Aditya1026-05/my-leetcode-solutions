class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> ans;
        int high = *max_element(arr.begin(), arr.end())+k;

        unordered_map<int, int> mp;

        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }

        for(int i = 1; i <= high; i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }
        return ans[k-1];
    }
};