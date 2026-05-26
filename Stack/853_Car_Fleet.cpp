class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, int>> ps;
        // Using a stack of doubles to prevent decimal truncation
        stack<double> st; 
        
        for (int i = 0; i < n; i++) {
            ps.push_back({position[i], speed[i]});
        }
        
        // Sort descending: cars closest to the target will be processed first
        sort(ps.rbegin(), ps.rend());

        for (int i = 0; i < n; i++) {
            // Fix: Access individual pairs with ps[i] and use double for precise time
            double time = (double)(target - ps[i].first) / ps[i].second;

            // If the stack is empty, or this car takes MORE time than the fleet in front of it,
            // it cannot catch up. It forms a brand new fleet!
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
            // If time <= st.top(), this car catches up to the fleet in front 
            // and simply becomes part of it (we do nothing).
        }

        return st.size();
    }
};
