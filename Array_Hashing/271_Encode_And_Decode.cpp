class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string fnl = "";
        for(auto c: strs){
            fnl += to_string(c.length()) + '#' + c; // it's like 5#Hello
        }
        return fnl;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i =0 ;

        while(i < s.length()){
            int j =i;
            while(s[j] != '#') j++;

            int length = stoi(s.substr(i, j-i)); // len = 4
            i = j + 1; 
            ans.push_back(s.substr(i, length)); // pushing substring to array
            i += length;
        }         

        
        
        return ans;
    }
};
