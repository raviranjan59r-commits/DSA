class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(1e5+1,0);

        for(int i=0;i<nums1.size();i++){
            int x=abs(nums1[i]-nums2[i]);
            diff[x]++;
        }

        int op=k1+k2;

        for(int i=1e5;i>=1;i--){
            if(op==0) break;
            if(op>=diff[i]){
                diff[i-1]+=diff[i];
                op-=diff[i];
                diff[i]=0;
            }
            else{
                diff[i]-=op;
                diff[i-1]+=op;
                break;
            }
        }

        long long ans=0;
       
        for(int i=1;i<=1e5;i++){
           if(diff[i]>0) ans+=1LL * i * i * diff[i];
        }

       return ans;
    }
};