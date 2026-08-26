class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        //by using line sweep technique
        map<int,int> events;

        for(int i=0;i<logs.size();i++){
            events[logs[i][0]]++;
            events[logs[i][1]]--;
        }
        int maxpopulation=0;
        int population=0;
        int ans;
        for(auto &[year,delta]:events){
            population+=delta;

            if(population>maxpopulation){
                maxpopulation=population;
                ans=year;
            }
        }
        return ans;
    }
};