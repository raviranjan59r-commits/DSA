class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans="";

        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]=='('){
                    st.push(s[i]);
                    ans+='(';
                }
                else{
                    st.pop();
                    if(!st.empty()){
                        ans+=')';
                    }
                }
            }
        }
        return ans;
    }
};