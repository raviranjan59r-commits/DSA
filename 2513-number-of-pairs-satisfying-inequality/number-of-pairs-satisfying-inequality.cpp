class Solution {
public:
    vector<int> st;

    void point_update(int i,int l,int r,int idx){
        if(l==r){
            st[i]+=1;
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

    long long numberOfPairs(vector<int>& nums1,vector<int>& nums2,int diff){
        int n=nums1.size();

        vector<long long> a(n);

        for(int i=0;i<n;i++){
            a[i]=(long long)nums1[i]-nums2[i];
        }

        // coordinate compression
        vector<long long> vals=a;

        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());

        st.resize(4*n,0);

        long long ans=0;

        for(int j=0;j<n;j++){

            long long limit=a[j]+diff;

            // number of previous a[i] <= limit
            int idx=upper_bound(vals.begin(),vals.end(),limit)-vals.begin()-1;

            if(idx>=0){
                ans+=Query(0,0,n-1,0,idx);
            }

            // insert current a[j]
            int pos=lower_bound(vals.begin(),vals.end(),a[j])-vals.begin();

            point_update(0,0,n-1,pos);
        }

        return ans;
    }
};