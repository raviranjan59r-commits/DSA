class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1002]={0};

        for(auto &trip:trips){
            diff[trip[1]]+=trip[0];
            diff[trip[2]]-=trip[0];
        }
        int current=0;
        for(int i=0;i<1002;i++){
            current+=diff[i];
            if(current>capacity) return false;
        }
        return true;
    }
};