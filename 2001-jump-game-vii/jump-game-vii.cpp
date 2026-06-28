class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int  n= s.length();
        vector<bool> dp(n,0);
        dp[0]=true;
        int far=0;
        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            int low=max(i+minJump,far);
            int high=i+maxJump;
            if(high>=n) high=n-1;
            if(high<=far) continue;
            for(int j=low;j<=high;j++){
                if(s[j]=='0') dp[j]=1; 
            }
                far=max(far,high);
        }
        return dp[n-1];
    }
};