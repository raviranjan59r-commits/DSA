class Solution {
public:
    vector<int> st;

    void update(int node,int l,int r,int pos){
        if(l==r){
            st[node]++;
            return;
        }

        int mid=(l+r)/2;

        if(pos<=mid)
            update(2*node,l,mid,pos);
        else
            update(2*node+1,mid+1,r,pos);

        st[node]=st[2*node]+st[2*node+1];
    }

    int query(int node,int l,int r,int ql,int qr){
        if(qr<l || r<ql)
            return 0;

        if(ql<=l && r<=qr)
            return st[node];

        int mid=(l+r)/2;

        return query(2*node,l,mid,ql,qr)
             + query(2*node+1,mid+1,r,ql,qr);
    }

    int countRangeSum(vector<int>& nums,int lower,int upper) {
        int n=nums.size();

        vector<long long> pre(n+1,0);

        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+nums[i];

        vector<long long> v=pre;

        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());

        int m=v.size();
        st.assign(4*m,0);

        int ans=0;

        for(int i=0;i<=n;i++){
            long long x=pre[i];

            int left=lower_bound(v.begin(),v.end(),x-upper)-v.begin()+1;
            int right=upper_bound(v.begin(),v.end(),x-lower)-v.begin();

            if(left<=right)
                ans+=query(1,1,m,left,right);

            int pos=lower_bound(v.begin(),v.end(),x)-v.begin()+1;
            update(1,1,m,pos);
        }

        return ans;
    }
};