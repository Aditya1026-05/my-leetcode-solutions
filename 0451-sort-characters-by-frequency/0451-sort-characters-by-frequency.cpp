class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(char c : s){
            freq[c]++;
        }
        vector<pair<char,int>> arr;

        for(auto &it : freq){
            arr.push_back(it);
        }

        sort(arr.begin(), arr.end(),
        [](auto &a, auto &b){
            return a.second > b.second;
        });

        string ans;

        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[i].second;j++){
                ans.push_back(arr[i].first);
            }
        }
        return ans;
    }
};