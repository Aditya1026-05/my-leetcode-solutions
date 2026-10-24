class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }else{
                    width = i - st.top() -1;
                }
                int area = h * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();

            int width;
            if (st.empty()) {
                width = n;
            } else {
                width = n - st.top() - 1;
            }

            int area = h * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};






// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> left(n); //left smaller nearest - previous smaller element
//         vector<int> right(n);//right smaller nearest - next smaller element
//         stack<int> s;

//         //Right smaller
//         for(int i = n-1; i>=0; i-- ){
//             while(s.size() > 0 && heights[s.top()] >= heights[i]){
//                 s.pop();
//             }
//             right[i] = s.empty() ? n : s.top();
//             s.push(i);
//         }

//         while(!s.empty()){
//             s.pop();
//         }

//         //left smaller
//         for(int i = 0; i < n; i++){
//             while(s.size() > 0 && heights[s.top()] >= heights[i]){
//                 s.pop();
//             }
//             left[i] = s.empty() ? -1 : s.top();
//             s.push(i);
//         }

//         int ans = 0;
//         for(int i=0; i<n; i++){
//             int width = right[i] - left[i] -1;
//             int currArea = heights[i] * width;
//             ans = max(currArea,ans);
//         }

//         return ans;

//     }
// };