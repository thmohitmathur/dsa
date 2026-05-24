class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0 ) return true;
        stack<char> st; // stack 
        for(int i =0; i < s.size(); i++){
            char temp = s[i];
            if(temp == '(' || temp == '[' || temp == '{') st.push(temp); // pushing only opening
            else{ // comaprin now closing barcets
                if(st.empty()) return false; // if empty do somethign
                if(temp == ')' && st.top() == '(' || temp == ']' && st.top() == '[' || temp == '}' && st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }
            }

        }
        return (!st.empty())?false:true;
    }
};
