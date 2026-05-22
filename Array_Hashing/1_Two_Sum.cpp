class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){

            temp = target - nums[i]; // like 9 - nums[i] then findidng the equivlaent 9-2 = 7 so find 7 in the array

            if(mp.find(temp) != mp.end()){
                return {mp[temp], i};
            }

            mp[nums[i]] = i;

        }   
    
        return {-1, -1};
    }
