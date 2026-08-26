class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> events;

        for(auto &trip:trips){
            events[trip[1]]+=trip[0];
            events[trip[2]]-=trip[0];
        }
        int current=0;
        for(auto &[a,b]:events){
            current+=b;
            if(current>capacity) return false;
        }
        return true;
    }
};