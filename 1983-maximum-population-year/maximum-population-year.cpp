class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        //using difference array
        int year[102]={0};

        for(int i=0;i<logs.size();i++){
            year[logs[i][0] - 1950]+=1;
            year[logs[i][1] - 1950]-=1;
        }
        int maxpopulation=0;
        int population=0;
        int ans=1950;
        for(int i=0;i<102;i++){
            population+=year[i];
            if(population>maxpopulation){
                maxpopulation=population;
                ans=1950+i;
            }
        }
        return ans;
    }
};