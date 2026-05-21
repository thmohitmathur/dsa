class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i: nums){ // counting frequince
            mp[i]++;
        }

        vector<vector<int>> arr;
        for(auto it = mp.begin(); it != mp.end(); it++){
            arr.push_back({it->second, it->first}); // stroing map into array
        }
        sort(arr.begin(), arr.end());
        int kc = 0;
        vector<int> ans;
        for(int i = arr.size()-1; i >= 0; i--){ // printing top k freq
            if(kc == k) break;

            ans.push_back(arr[i][1]);
            kc++;
        }
        return ans;
    }
