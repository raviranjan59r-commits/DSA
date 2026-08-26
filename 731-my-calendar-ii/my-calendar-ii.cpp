class MyCalendarTwo {
public:
    map<int,int> mp;
    // priority_queue<int,vector<int>,greater<int>> pq;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        // finding max overlapping
        int ans=0;
        for(auto & [time,delta]:mp){
            ans+=delta;
            if(ans>2){
                mp[startTime]-=1;
                mp[endTime]+=1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */