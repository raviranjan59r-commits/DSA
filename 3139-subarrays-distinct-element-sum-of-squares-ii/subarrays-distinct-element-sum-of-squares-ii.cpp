class Solution {
public:
    const long long MOD=1e9+7;

    struct Node{
        long long sum=0;
        long long sq=0;
        long long lazy=0;
    };

    vector<Node> st;

    void apply(int node,int l,int r,long long val){
        long long len=r-l+1;

        st[node].sq=(st[node].sq+2*val*st[node].sum+len*val%MOD*val)%MOD;
        st[node].sum=(st[node].sum+len*val)%MOD;
        st[node].lazy=(st[node].lazy+val)%MOD;
    }

    void push(int node,int l,int r){
        if(st[node].lazy==0 || l==r)
            return;

        int mid=(l+r)/2;
        long long val=st[node].lazy;

        apply(2*node+1,l,mid,val);
        apply(2*node+2,mid+1,r,val);

        st[node].lazy=0;
    }

    void update(int node,int l,int r,int ql,int qr){
        if(qr<l || r<ql)
            return;

        if(ql<=l && r<=qr){
            apply(node,l,r,1);
            return;
        }

        push(node,l,r);

        int mid=(l+r)/2;

        update(2*node+1,l,mid,ql,qr);
        update(2*node+2,mid+1,r,ql,qr);

        st[node].sum=(st[2*node+1].sum+st[2*node+2].sum)%MOD;
        st[node].sq=(st[2*node+1].sq+st[2*node+2].sq)%MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n=nums.size();

        st.assign(4*n,Node());

        unordered_map<int,int> last;
        long long ans=0;

        for(int i=0;i<n;i++){
            int prev=-1;

            if(last.count(nums[i]))
                prev=last[nums[i]];

            update(0,0,n-1,prev+1,i);

            ans=(ans+st[0].sq)%MOD;

            last[nums[i]]=i;
        }

        return ans;
    }
};