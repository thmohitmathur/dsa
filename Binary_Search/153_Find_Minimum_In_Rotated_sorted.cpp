class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; 
        int r = nums.size()-1;
        int mid = 0;
        int ans = INT_MAX;
        while(l < r){
            mid = l + (r-l)/2;
            ans = min(nums[mid], ans);
            if(nums[l] < nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
            
        }

        return ans;
    }
};
