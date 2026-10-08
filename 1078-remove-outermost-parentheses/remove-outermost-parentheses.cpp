class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=0;
        string ans="";

        for(auto ch:s){
            if(ch=='('){
                if(depth!=0) ans+=ch;
                depth++;
            }
            else{
                depth--;
                if(depth!=0) ans+=ch;
            }
        }
        return ans;
    }
};