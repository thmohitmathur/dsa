class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxe = INT_MIN;

        for(int i =0 ; i < n; i++){
            int temp = heights[i];
            while(!st.empty() && heights[st.top()] > temp){
                int height = heights[st.top()]; // The height of our rectangle
                st.pop();
                
                // If stack is empty, this bar was the shortest seen so far, so width is 'i'
                // Otherwise, width is bounded by current index 'i' and the index below it in stack
                int width = st.empty() ? i : (i - st.top() - 1);
                
                maxe = max(maxe, height * width);
            }
            st.push(i);
        }
            while(!st.empty()){
                int height = heights[st.top()]; // The height of our rectangle
                st.pop();
                
                // If stack is empty, this bar was the shortest seen so far, so width is 'i'
                // Otherwise, width is bounded by current index 'i' and the index below it in stack
                int width = st.empty() ? n : (n - st.top() - 1);
                
                maxe = max(maxe, height * width);   

            }
        
        return maxe;

    }
};
