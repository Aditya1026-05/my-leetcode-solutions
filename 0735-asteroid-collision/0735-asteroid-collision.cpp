class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int asteroid : asteroids){
           while(!st.empty() && st.top() > 0 && st.top() < -asteroid){
            st.pop();
           }
           if(st.empty() || st.top() < 0 || asteroid > 0){
            st.push(asteroid);
           }else if(st.top() == -asteroid){
            st.pop();
           }
        }
        vector<int> ans(st.size());
        for(int i = st.size() - 1; i>= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};