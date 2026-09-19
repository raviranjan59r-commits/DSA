class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int ones=count(s.begin(),s.end(),'1');

        vector<int> inactive;
        int i=0;
        while(i<n){
            int j=i;
            if(s[j]=='0'){
                while(j<n && s[j]=='0'){
                    j++;
                }
                inactive.push_back(j-i);
                i=j;
            }
            else{
                i++;
            }
        }
        int maxConversion=0;
        for(int i=1;i<inactive.size();i++){
            maxConversion=max(maxConversion,inactive[i]+inactive[i-1]);
        }
        return maxConversion+ones;
    }
};