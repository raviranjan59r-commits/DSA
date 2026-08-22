class Solution {
public:
    using ll=long long;

    ll cunt_smaller_elements(ll num,vector<int>&coins){
        //we will use principle of inclusion exclusion
        //there will be 2^n-1 expression we will represent them using bit mask 
        ll total_counts=0;

        int n=coins.size();
        for(int exp=1;exp<(1<<n);exp++){
            ll lcm=0;
            ll order=0;

            for(int i=0;i<n;i++){
                if(exp & (1<<i)){//bit is set
                    order++;
                    if(lcm==0){
                        lcm=coins[i];
                    }
                    else{
                        lcm=lcm * coins[i]/gcd(lcm,coins[i]);
                    }
                }
            }
            if(order%2==1) total_counts+=num/lcm;
            else total_counts-=num/lcm;
        }

        return total_counts;
    }

    ll findKthSmallest(vector<int>& coins, int k) {
        ll l=0;
        ll r=(ll)(*max_element(coins.begin(),coins.end())) * k;

        ll ans=0;

        while(l<=r){
            ll mid=l + (r-l)/2;

            if(cunt_smaller_elements(mid,coins)>=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};