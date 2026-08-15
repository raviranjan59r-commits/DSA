class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {

        int n=special.size();

        sort(special.begin(),special.end());

        // if(special[0]!=bottom) special.insert(special.begin(),bottom-1);
        // if(special[n-1]!=top) special.push_back(top+1);

        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,special[i]-special[i-1]-1);
        }
        ans=max(special[0]-bottom,ans);
        ans=max(top-special[n-1],ans);
        return ans;
    }
};