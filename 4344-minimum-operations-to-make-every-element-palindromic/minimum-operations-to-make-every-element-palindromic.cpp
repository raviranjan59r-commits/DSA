class Solution {
public:
    vector<int> pal[2];

    long long makePal(int x,int len){
        long long res=x;
        int t=x;
        
        if(len%2)
            t/=10;
        
        while(t){
            res=res*10+t%10;
            t/=10;
        }
        
        return res;
    }

    void generate(){
        for(int len=1;len<=9;len++){
            int half=(len+1)/2;
            
            int start=1;
            for(int i=1;i<half;i++)
                start*=10;
            
            int end=start*10-1;
            
            for(int x=start;x<=end;x++){
                long long p=makePal(x,len);
                
                pal[p%2].push_back(p);
            }
        }
    }

    long long get(int x){
        vector<int>&v=pal[x%2];
        
        auto it=lower_bound(v.begin(),v.end(),x);
        
        long long ans=LLONG_MAX;
        
        if(it!=v.end())
            ans=min(ans,abs((long long)x-*it));
        
        if(it!=v.begin()){
            --it;
            ans=min(ans,abs((long long)x-*it));
        }
        
        return ans/2;
    }

    long long minOperations(vector<int>& nums){
        generate();
        
        long long ans=0;
        
        for(auto x:nums)
            ans+=get(x);
        
        return ans;
    }
};