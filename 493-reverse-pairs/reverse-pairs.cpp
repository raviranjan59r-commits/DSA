class Solution {
public:
    vector<int> st;

    void point_update(int i,int l,int r,int idx){
        if(l==r){
            st[i]++;
            return;
        }

        int mid=l+(r-l)/2;

        if(mid>=idx){
            point_update(i*2+1,l,mid,idx);
        }
        else{
            point_update(i*2+2,mid+1,r,idx);
        }

        st[i]=st[i*2+1]+st[i*2+2];
    }

    int Query(int i,int l,int r,int start,int end){
        if(l>end || r<start) return 0;

        if(start<=l && r<=end){
            return st[i];
        }

        int mid=l+(r-l)/2;

        return Query(i*2+1,l,mid,start,end)
             + Query(i*2+2,mid+1,r,start,end);
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();

        // store unique element in sorted order

        vector<int>v=nums;

        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());

        int m=v.size();

        st.assign(4*m,0);

        long long count=0;

        for(int i=0;i<n;i++){

            long long x=2LL*nums[i];

            int pos=upper_bound(v.begin(),v.end(),x)-v.begin();

            count+=Query(0,0,m-1,pos,m-1);

            int idx=lower_bound(v.begin(),v.end(),nums[i])-v.begin();

            point_update(0,0,m-1,idx);
        }

        return count;
    }
};