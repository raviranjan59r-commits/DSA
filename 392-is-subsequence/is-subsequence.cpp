class Solution {
public:
    bool f(string &s, string &t,int i,int j){
        //base case
        if(i==-1) return true;
        if(j<0) return false; 

        if(s[i]==t[j]) {
            if(f(s,t,i-1,j-1)){
                return true;
            }
        }
        else{
            if(f(s,t,i,j-1)){
                return true;
            }
        }
        return false;
    }
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        return f(s,t,m-1,n-1);
    }
};