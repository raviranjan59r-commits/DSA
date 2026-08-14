class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();

        vector<int> ans(n,-1);
        set<int> dry_days;//it store indices of dry days

        unordered_map<int,int> last_rain;//it store {key,vlaue}=> {rains[i],idx}
        //it store last rain idex of lake rains[i]

        for(int i=0;i<n;i++){
            if(rains[i]==0){ // no rain
                dry_days.insert(i);
            }
            else{ // rains
                int lake=rains[i];

                //cheack if its already filled or not

                if(last_rain.count(lake)){//already filled
                    // then cheack that the is there any dry days present after last days
                    auto it=dry_days.upper_bound(last_rain[lake]);

                    if(it==dry_days.end()){//no dry days present
                        return {};
                    }
                    //dry day present
                    ans[*it]=lake;
                    dry_days.erase(it);
                    last_rain[lake]=i;
                }
                else{//not filled
                    last_rain[lake]=i;
                }
            }
        } 
        while(!dry_days.empty()){
            ans[*dry_days.begin()] = 1;
            dry_days.erase(dry_days.begin());
        }
        return ans;
    }
};