class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(int i = 0; i < t.size(); i++){
            need[t[i]]++;
        }
        int required = t.size();
        int matched = 0;

        int left = 0;

        int minlen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++){
            char ch = s[right];

            window[ch]++;
            if(window[ch] <= need[ch]) matched++;

            while(matched == required){
                int currlen = right - left +1;
                if(currlen < minlen){
                    minlen = currlen;
                    start = left;
                }

                if(window[s[left]] <= need[s[left]]){
                    matched--;
                }
                window[s[left]]--;
                left++;

            }

        }
        if(minlen == INT_MAX) return "";
        return s.substr(start, minlen);

    }
};