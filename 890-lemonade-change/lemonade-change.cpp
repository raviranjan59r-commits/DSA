class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        mp[5]=0;
        mp[10]=0;
        mp[20]=0;
        for(auto bill:bills){
            if(bill==5) mp[5]++;
            else if(bill==10) {
                mp[10]++;
                mp[5]--;
                if(mp[5]<0) return false;
            }
            else if(bill==20){
                mp[20]++;
                if(mp[10]>0){
                    mp[10]--;
                    mp[5]--;
                    if(mp[5]<0 || mp[10]<0) return false;
                }
                else{
                    mp[5]-=3;
                    if(mp[5]<0) return false;
                }
            }
        }
        return true;
    }
};