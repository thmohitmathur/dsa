class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        // Step 1: Sort the array to use two pointers
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Optimization: If the current number is greater than 0, 
            // three positive numbers can never sum to 0. Stop early!
            if (nums[i] > 0) break;

            // Skip duplicate values for the anchor element 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    // Move both pointers after a successful match
                    l++;
                    r--;
                    
                    // Skip duplicate values for 'l' to avoid duplicate triplets
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    
                    // Skip duplicate values for 'r' to avoid duplicate triplets
                    while (l < r && nums[r] == nums[r + 1]) r--;
                    
                } else if (sum > 0) {
                    r--; // Sum is too large, move right pointer down
                } else {
                    l++; // Sum is too small, move left pointer up
                }
            }
        }
        return ans;
    }
};
// another approach i just use set to remove the duplicate entries
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> us;;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int l = i+1;
            int r = nums.size()-1;

            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    us.insert({nums[i],nums[l],nums[r]});
                    r--;
                }else if(sum > 0){
                    r--;
                }else if(sum < 0){
                    l++;
                }
            }
        }
        for(auto it = us.begin(); it != us.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};
