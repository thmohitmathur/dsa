class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 1. Dump all numbers into a hash set to remove duplicates 
        // and get O(1) average lookup times.
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        // 2. Iterate through the set
        for (int num : s) {
            // Check if 'num' is the absolute START of a sequence.
            // If (num - 1) is in the set, then 'num' is NOT the start, so we skip it.
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // 3. Keep checking for the next numbers in line to build the streak
                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update our record holder
                longest = max(longest, currentStreak);
            }
        }
        
        return longest;
    }
