class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        int start = 0;
        string ans ;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                depth++;
            }else{
                depth--;
            }
            if(depth == 0){
                for(int j = start+1; j<= i-1;j++){
                    ans+= s[j];
                }
              start = i + 1;  
            }
            
        }
        return ans;
    }
};