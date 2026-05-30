class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        // weird ass formula 
        unordered_map<char, int> mp;
        int l = 0;
        int subs = 0;
        int maxe = INT_MIN; 
        int max_freq = 0;
        for(int r = 0; r < s.length(); r++)
        {   
            mp[s[r]]++;
            max_freq = max(max_freq, mp[s[r]]);

            if((r - l + 1) - max_freq > k){
                mp[s[l]]--;
                l ++;
            }
            maxe = max(r - l + 1, maxe);

        }


        return maxe;
    }
};