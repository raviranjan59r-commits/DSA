class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<bool>> isPalindrome;
    int f(string &s,int k,int i,int j){
        if(i>=s.length() || j>=s.length()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(isPalindrome[i][j]){
            // 3 cases
            //take
            int take=1+f(s,k,j+1,j+k);
            //expand
            int expand=f(s,k,i,j+1);
            //slide
            int slide=f(s,k,i+1,j+1);

            return dp[i][j]= max({take,expand,slide});
        }
        //if not 2 cases
        //expand
        int expand=f(s,k,i,j+1);
        //slide
        int slide=f(s,k,i+1,j+1);

        return dp[i][j]=max(expand,slide);
    }
    int maxPalindromes(string s, int k) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        isPalindrome.resize(n+1,vector<bool>(n+1,false));

        // precompute ispalindrome

        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                //3 cases
                // case1 -> i==j
                if(i==j) isPalindrome[i][j]=true;

                // length=2
                else if(i+1==j){
                    isPalindrome[i][j]= (s[i]==s[j]);
                }
                else{
                    isPalindrome[i][j]=(s[i]==s[j]) && isPalindrome[i+1][j-1];
                }
            }
        }
        return f(s,k,0,k-1);
    }
};