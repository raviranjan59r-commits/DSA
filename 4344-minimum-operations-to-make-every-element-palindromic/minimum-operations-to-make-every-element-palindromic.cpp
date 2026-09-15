class Solution {
public:
    long long minOperations(vector<int>& nums){
        static const auto pals=[]()->pair<vector<long long>,vector<long long>>{
            vector<long long> oddv,evenv;
            
            // Generate all palindromes using their first half
            for(long long r=1;r<=99999;r++){
                
                // Generate odd length palindrome
                long long x=r,t=r/10;
                
                while(t){
                    x=x*10+t%10;
                    t/=10;
                }
                
                if(x&1) oddv.push_back(x);
                else evenv.push_back(x);
                
                // Generate even length palindrome
                x=r;
                t=r;
                
                while(t){
                    x=x*10+t%10;
                    t/=10;
                }
                
                if(x&1) oddv.push_back(x);
                else evenv.push_back(x);
            }
            
            // Sort so we can use binary search
            sort(oddv.begin(),oddv.end());
            sort(evenv.begin(),evenv.end());
            
            return {move(oddv),move(evenv)};
        }();
        
        long long ans=0;
        
        for(int v:nums){
            // Since we can only change by 2, parity never changes
            const vector<long long>&p=(v&1)?pals.first:pals.second;
            
            // Find the first palindrome >= v
            auto it=lower_bound(p.begin(),p.end(),v);
            
            long long best=LLONG_MAX;
            
            // Check palindrome on the right
            if(it!=p.end())
                best=min(best,*it-v);
            
            // Check palindrome on the left
            if(it!=p.begin()){
                --it;
                best=min(best,v-*it);
            }
            
            // Every operation changes the number by 2
            ans+=best/2;
        }
        
        return ans;
    }
};