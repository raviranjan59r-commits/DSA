class Solution {
public:
    struct node{
        long long score=-1;
        vector<int> idxs;
    };
    vector<int> nextIdx;
    vector<vector<node>> dp;
    int get_next_index(vector<vector<int>>& intervals,int last){
        int lo=0;
        int hi=intervals.size()-1;
        int idx=-1;
        while(lo<=hi){
            int mid=lo +(hi-lo)/2;
            if(intervals[mid][0]>last){
                idx=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return idx;
    }
    node solve(vector<vector<int>>& intervals,int i,int k){
        // base case
        if(k==0 || i>=intervals.size()){
            return node();
        }
        if(dp[i][k].score!=-1) return dp[i][k];
        //not take
        node not_take=solve(intervals,i+1,k);
        // current values
        int weight = intervals[i][2];
        int idx    = intervals[i][3];
        int j      = nextIdx[i];
        //take
        node temp=solve(intervals,j,k-1);

        node take;

        take.score=weight+temp.score;
        take.idxs=temp.idxs;
        take.idxs.push_back(idx);

        sort(take.idxs.begin(),take.idxs.end());

        node  result;

        if(not_take.score>take.score){
            result=not_take;
        }
        else if(take.score>not_take.score){
            result=take;
        }
        else{//both scores are equal
            result = take.idxs<not_take.idxs?take:not_take;
        }
        return dp[i][k]=result;

    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        //modify interval or make a completely new array to store the actual position of the interval

        for(int i=0;i<n;i++) intervals[i].push_back(i);

        //sort
        sort(intervals.begin(),intervals.end());

        //precompute the nextIdx array
        nextIdx.resize(n);

        for(int i=0;i<n;i++){
            int last=intervals[i][1];
            nextIdx[i]=get_next_index(intervals,last);
        }
        int k=4;
        dp.resize(n+1,vector<node>(k+1));
        node ans=solve(intervals,0,k);

        return ans.idxs;

    }
};