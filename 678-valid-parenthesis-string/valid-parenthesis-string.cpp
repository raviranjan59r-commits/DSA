class Solution {
public:
    int t[100][100];
    bool solve(string &s ,int open,int i){
        if(open<0) return false;
        if(i>=s.length()){
            return open==0;
        }
        if(t[open][i]!=-1) return t[open][i];
        if(s[i]=='('){
            return t[open][i]=solve(s,open+1,i+1);
        }
        else if(s[i]==')'){
            return t[open][i]=solve(s,open-1,i+1);
        }
        else{
            return t[open][i]=(solve(s,open+1,i+1) || solve(s,open-1,i+1) || solve(s,open,i+1));
        }
    }
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,0);
    }
};