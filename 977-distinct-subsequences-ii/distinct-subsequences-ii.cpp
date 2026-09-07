class Solution {
public:
    int M=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();

        vector<long long> dp(n+1,1);

        unordered_map<char,int> last;

        for(int i=1;i<=n;i++){
            char ch=s[i-1];
            dp[i]=(2 * dp[i-1])%M;

            if(last.count(ch)){
                dp[i]=(dp[i] - dp[last[ch]-1] + M)%M;
            }
            last[ch]=i;
        }
        return (dp[n]-1 + M)%M;
    }
};