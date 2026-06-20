class Solution {
public:
    string minWindow(string s, string t) {
        int mine = INT_MAX;
        int win = t.length();
        if(win == 0) return "";
        vector<int> s_co(128,0);
        vector<int> t_co(128,0);
        int need = 0;
        for(auto c: t){
            if(t_co[c] == 0) need++; 
            t_co[c]++;
        }
        int min_len = INT_MAX;
        int start_idx = -1;
        int have = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            s_co[c]++;
            
            if (t_co[c] > 0 && s_co[c] == t_co[c]) {
                have++;
            }
            while(have == need){
                if(r-l+1  < min_len){
                    min_len = r - l + 1;
                    start_idx = l;
                }
                char left_char = s[l];
                s_co[left_char]--;

                if (t_co[left_char] > 0 && s_co[left_char] < t_co[left_char]) {
                    have--;
                }
                l++;
            }
        }
        return start_idx == -1 ? "" : s.substr(start_idx, min_len);
    }
};
