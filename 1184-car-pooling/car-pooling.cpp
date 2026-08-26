class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> events;

        for(auto &trip:trips){
            int c = trip[0];
            int s = trip[1];
            int e = trip[2];
            events[s]+=c;
            events[e]-=c;
        }
        int current=0;
        for(auto &[a,b]:events){
            current+=b;
            if(current>capacity) return false;
        }
        return true;
    }
};