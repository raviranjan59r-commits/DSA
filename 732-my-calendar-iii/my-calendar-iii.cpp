class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        // finding max overlapping
        int ans=0;
        int maxans=0;
        for(auto & [time,delta]:mp){
            ans+=delta;
            maxans=max(ans,maxans);
        }
        return maxans;;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */