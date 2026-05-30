class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // just add freq of s1 and s2 both then if equal return true or false;
        int win = s1.length();
        vector<int> s1_doer(26,0);
        vector<int> s2_doer(26,0);
        bool flag = false;
        for(auto c: s1){
            s1_doer[c - 'a']++;
        }

        int l = 0;
        for(int r = 0; r < s2.length(); r++){
            s2_doer[s2[r] - 'a']++;
            if(r-l+1 == win){
                if(s1_doer == s2_doer) return true;

                s2_doer[s2[l] - 'a']--;
                l++;
            }

        }

        return flag;
    }
};
