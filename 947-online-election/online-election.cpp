class TopVotedCandidate {
public:
    vector<int> person;
    vector<int> time;
    vector<int> leaders;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        person=persons;
        time=times;

       //constructing leaders

        unordered_map<int,int> freq;
        int leader=person[0];
        int max_freq=0;

        for(int ele : person){
            if(++freq[ele]>=max_freq){
                leader=ele;
                max_freq=freq[ele];
            }
            leaders.push_back(leader);
        }
    }

  

    
    
    int q(int t) {
        
        auto it=lower_bound(time.begin(),time.end(),t);

        int idx=it-time.begin();
        if(idx >=time.size() || time[idx]!=t) idx--;

        return leaders[idx];
        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */