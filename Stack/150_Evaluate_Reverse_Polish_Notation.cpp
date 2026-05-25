class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //simply use stackk to store number if operattor come get top 2 values and perform the function.
        stack<int> st;
        for(auto c: tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){ 
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                if(c == "+"){
                    int val = temp1 + temp2;
                    st.push(val);
                }
                if(c == "-"){
                    int val = temp2 - temp1;
                    st.push(val);
                }
                if(c == "*"){
                    int val = temp1 * temp2;
                    st.push(val);
                }
                if(c == "/"){
                    int val = temp2  /temp1;
                    st.push(val);
                }
            }else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
