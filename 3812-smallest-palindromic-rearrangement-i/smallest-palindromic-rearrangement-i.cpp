class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        int n=s.length();
        string ans(n,'#');

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int idx=0;

        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;

            if(freq[i]%2==1){
                ans[s.length()/2]='a'+i;
                freq[i]--;
            }
            int count = freq[i]/2; 
            while(count!=0){
                ans[idx]='a'+i;
                ans[n-idx-1]='a' + i;
                count--;
                idx++;
            }
        }
        return ans;
    }
};