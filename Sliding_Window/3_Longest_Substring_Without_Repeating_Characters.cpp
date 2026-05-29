class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // nrml sliding window r going to end we pust char in set and use while to find its same char if we find we erase it and l++ then we find the max lenght
        int l = 0;
        int r = 0;
        int maxe = 0;
        unordered_set<char> se;
        for(int r = 0; r < s.length(); r++){
            while(se.find(s[r]) != se.end()){
                se.erase(s[l]);
                l++;
            }
            maxe = max(r - l + 1, maxe);
            se.insert(s[r]);
        }
        return maxe;
    }
};
