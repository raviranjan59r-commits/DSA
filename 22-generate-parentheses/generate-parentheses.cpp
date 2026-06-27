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
            s+=')';
            f(n,o,c+1,s);
            s.pop_back();
        }
         s+='(';
        f(n,o+1,c,s);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        
        // string s="";

        f(n,0,0,"");

        return ans;
    }
};