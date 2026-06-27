class Solution {
public:
    vector<string> ans;

    void f(int n,int o,int c,string s){// opening - closing
        if(n==o && n == c){
            ans.push_back(s);
            return;
        }
        if(o>n) return;
        if(o > c){
            f(n,o,c+1,s+')');
        }

        f(n,o+1,c,s+'(');
    }

    vector<string> generateParenthesis(int n) {
        
        // string s="";

        f(n,0,0,"");

        return ans;
    }
};