class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        int ans = 0;
        int prefix = 0; 
        mp[0] = 1;

        for(int i = 0 ; i < nums.size(); i++){
            prefix += nums[i];
            int need = prefix - k;

            if(mp.find(need) != mp.end()) ans += mp[need];
            mp[prefix]++;
        }
        return ans;
    }
};