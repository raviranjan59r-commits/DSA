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
        st[i]=st[i*2+1] + st[i*2+2];
    }
    int Query(int i,int l,int r,int start,int end){
        if(l>end || r<start) return 0;
        if(start<=l && r<=end){
            return st[i];
        }
        int mid=l+(r-l)/2;
        return Query(i*2+1,l,mid,start,end) + Query(i*2+2,mid+1,r,start,end);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        st.resize(4*20003,0);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            int x=10000+nums[i];
            ans[i]=Query(0,0,20001,0,x-1);
            point_update(0,0,20001,10000+nums[i]);
        }
        return ans;
    }
};