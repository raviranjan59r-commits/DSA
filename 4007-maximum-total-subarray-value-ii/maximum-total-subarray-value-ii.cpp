class Solution {
public:
    using p=pair<int,int>;
    using pp = pair<int,pair<int,int>>;
    vector<p> st;
    void build_tree(vector<int>&nums,int l,int r,int idx){
        if(l==r){
            st[idx]={nums[l],nums[l]};
            return;
        }

        int mid=(l+r)/2;

        build_tree(nums,l,mid,2*idx+1);
        build_tree(nums,mid+1,r,2*idx+2);

        st[idx]={
            max(st[2*idx+1].first,st[2*idx+2].first),
            min(st[2*idx+1].second,st[2*idx+2].second)
        };
    }
    p query(int start,int end,int i,int l,int r){
        //case 1-> outside/no overlap
        if(r<start || end<l){
            return {INT_MIN,INT_MAX};
        }

        //case 2-> complete overlap
        if(l>=start && r<=end){
            return st[i];
        }

        //case 3-> partial overlap
        int mid=(l+r)/2;

        p left=query(start,end,2*i+1,l,mid);
        p right=query(start,end,2*i+2,mid+1,r);

        return {max(left.first,right.first),min(left.second,right.second)};
    }

    long long maxTotalValue(vector<int>&nums,int k){
        int n=nums.size();
        st.resize(4*n);

        build_tree(nums,0,n-1,0);

        priority_queue<pp> pq;
        long long ans=0;

        for(int l=0;l<n;l++){
            p temp=query(l,n-1,0,0,n-1);
            int val=temp.first-temp.second;

            pq.push({val,{l,n-1}});
        }

        while(k--){
            auto temp=pq.top();
            pq.pop();

            ans+=temp.first;

            int l=temp.second.first;
            int r=temp.second.second;

            if(l<r){
                p temp=query(l,r-1,0,0,n-1);
                int val=temp.first-temp.second;

                pq.push({val,{l,r-1}});
            }
        }

        return ans;
    }
};