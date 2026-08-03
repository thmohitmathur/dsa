class Solution {
public:
    void doSo(vector<int>& nums, vector<vector<int>>& ans, int ind, vector<int>& temp){
        if(ind >= nums.size()){
            ans.push_back(temp);
            return;
        } 
        doSo(nums, ans, ind+1, temp);
        temp.push_back(nums[ind]);

        doSo(nums, ans, ind+1, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        doSo(nums, ans, 0, temp);
        return ans;
    }
};
