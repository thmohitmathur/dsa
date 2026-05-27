class Solution {
public:
    // ok so basically we find the nearest position to the target by calculating time then sort then in descending (near target) push on the stack only if it's not able to catch up monotonic ascending stack
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> ps;
        stack<double> st;
        int n = position.size();
        if(n == 0) return 0;
        for(int i = 0; i < n; i++){
            ps.push_back({position[i], speed[i]});
        }
        sort(ps.rbegin(), ps.rend());

        for(int i = 0; i < n; i++){
            double time = (double)(target - ps[i].first) / ps[i].second;

            if (st.empty() || time > st.top()) {
                st.push(time);
            }
            
        } // 1 1 7 3 12
            // 1 1 7 3 12
        return st.size();

    }
};
