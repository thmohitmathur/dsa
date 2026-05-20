class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // here we use hashmap with vecotr of strings
        vector<vector<string>> ans;
        int n = strs.size();

        for(int i = 0; i < n; i++){
            string label = strs[i];
            sort(label.begin(), label.end()); 
            mp[label].push_back(strs[i]); // stroing like aet: eat,tea,ate
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second); // just till the first map finsih it outputs functions
        }
        return ans;
    }
};
