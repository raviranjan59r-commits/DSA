class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        // int unreachable_drones=0;
        int idx=-1;
        int min_dist=1e9;

        for(int i=0;i<drones.size();i++){
            int dist=abs(drones[i][0]-target[0]) + abs(drones[i][1]-target[1]);
            if(dist<=drones[i][2]){
                if(min_dist>dist) {
                    min_dist=dist;
                    idx=i;
                }
            }
        }
        return idx;
    }
};