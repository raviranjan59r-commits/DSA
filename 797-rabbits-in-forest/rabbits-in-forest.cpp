class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;

        for(int x:answers) mp[x+1]++;
        int res=0;
        for(auto &[ans,freq]:mp){
            res+=ceil((double)freq/ans*1.0) *ans;
        }
        return res;
    }
};