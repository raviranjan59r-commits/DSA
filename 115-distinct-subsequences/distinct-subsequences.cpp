class Solution {
public:
    vector<vector<int>> dp;
    int f(string &s,int i, string &t,int j){
        if(j==t.length()) return 1;
        if(i>=s.length()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) {
            return dp[i][j]=f(s,i+1,t,j+1) + f(s,i+1,t,j);
        } 
        else{
            return dp[i][j]=f(s,i+1,t,j);
        }
    }
    int numDistinct(string s, string t) {

        //applying dp
        dp.resize(s.length()+1,vector<int>(t.length()+1,-1));

        return f(s,0,t,0);
    }
};