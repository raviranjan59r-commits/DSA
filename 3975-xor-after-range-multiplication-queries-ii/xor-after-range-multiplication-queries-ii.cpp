class Solution {
public:
    int m=1e9+7;
    using ll=long long;

    long long power(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half   = power(a, b/2);
        long long result = (half * half) % m;

        if(b % 2 == 1) {
            result = (result * a) % m;
        }

        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // we will use sqrt decomposition 

        int n=nums.size();
        int blocksize=ceil(sqrt(n));
        unordered_map<int,vector<vector<int>> > mp;

        for(int i=0;i<queries.size();i++){
            int k=queries[i][2];
            int v=queries[i][3];
            int l=queries[i][0];
            int r=queries[i][1];
            if(k>=blocksize){//use brute force
                for(int i=l;i<=r;i+=k){
                    nums[i]=(1ll * nums[i]*v)%m;
                }
            }
            else{
                mp[k].push_back(queries[i]);
            }
        }
        for(auto &[k,q]:mp){
            vector<int> diff(n,1);
            for(auto &query:q){
                int l=query[0];
                int r=query[1];
                int v=query[3];

                int steps=(r-l)/k;

                int next=l + (steps+1) * k;

                diff[l]=(1ll * diff[l]*v)%m;
                if(next < n){
                    diff[next] = (diff[next] * power(v, m-2)) % m;
                }
            }
            //cummulative product
            for(int i=0;i<n;i++){
                if(i-k>=0){
                    diff[i]=(1ll * diff[i] * diff[i-k])%m;
                }
            }
             //Apply diff to nums
            for(int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % m;
            }
        }
        // add this chamges into nums araay and take xor
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }

        return ans;
    }
};