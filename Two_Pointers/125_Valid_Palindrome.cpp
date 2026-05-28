class Solution {
public:
    bool isPalindrome(string s) {
        // u can try two pointer but i did remove special character then reverse and compared it
        string cp = "";
        for(auto c: s){
            if(isalnum(c)){
                cp += tolower(c);
            }
        }
        string cpp = cp;
        reverse(cp.begin(), cp.end());
        if(cpp == cp) return true;
        return false;

    }
};
