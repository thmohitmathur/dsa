class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int cntr = 1;
        int ans = 1; // Start at 1 because any single number is a sequence of 1
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]) continue; // Skip duplicates smoothly
            
            if(nums[i-1] == nums[i] - 1) {
                cntr++;
            }
            else{
                cntr = 1; // Break in sequence, reset counter
            }
            ans = max(cntr, ans);
        }
        return ans;
    }
};
