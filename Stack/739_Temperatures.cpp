class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // so basically we put index in the stack check if the next one is bigger then pop then do i - prev day and get the days 
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int prev_day = st.top();
                st.pop();
                ans[prev_day] = i - prev_day;
            }
            st.push(i);
        }
        return ans;
    }
};
