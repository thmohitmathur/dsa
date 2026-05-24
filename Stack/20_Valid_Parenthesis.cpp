                if(temp == ')' && st.top() == '(' || temp == ']' && st.top() == '[' || temp == '}' && st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }