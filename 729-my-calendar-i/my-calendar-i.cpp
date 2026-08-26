class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        // finding max overlapping
        int ans=0;
        for(auto & [time,delta]:mp){
            ans+=delta;
            if(ans>1){
                mp[startTime]-=1;
                mp[endTime]+=1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */