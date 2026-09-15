class Solution {
public:
    vector<int> st;
    vector<int> nums;
    void build_tree(int i,int l,int r){
        if(l==r){
            st[i]=l;
            return ;
        }
        int mid=l+(r-l)/2;

        build_tree(i*2+1,l,mid);
        build_tree(i*2+2,mid+1,r);

        int left_idx=st[i*2+1];
        int right_idx=st[i*2+2];

        if(nums[left_idx]>=nums[right_idx]){
            st[i]=left_idx;
        }
        else st[i]=right_idx;
    }
    int get(int i,int l,int r,int start,int end){
        //no overlap
        if(l>end ||r<start) return -1;

        //complete overlap
        if(start<=l && r<=end){
            return st[i];
        }
        // partial overlap
        int mid=l+(r-l)/2;
        int left_idx=get(i*2+1,l,mid,start,end);
        int right_idx=get(i*2+2,mid+1,r,start,end);

        if(left_idx==-1) return right_idx;
        if(right_idx==-1) return left_idx;

        if(nums[left_idx]>=nums[right_idx]){
            return left_idx;
        }
        else return right_idx;

    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        nums=heights;
        st.resize(4*n);
        build_tree(0,0,n-1);
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            if(a>b) swap(a,b);
            if((b>a && heights[b]>heights[a]) || a==b){
                ans[i]=b;
                continue;
            }
            //apply divide and conquer
            int start=1+max(a,b);
            int end=n-1;
            int max_val=max(heights[a],heights[b]);
            int idx=get(0,0,n-1,start,end);
            if(idx==-1 ||  nums[idx]<=max_val){
                ans[i]=-1;
                continue;
            }
            while(start<end){
                int mid=start+(end-start)/2;

                int index=get(0,0,n-1,start,mid);

                if(index!=-1 && heights[index]>max_val){
                    end=mid;
                    idx=index;
                }
                else start=mid+1;
            }
            ans[i]=idx;
        }
        return ans;
    }
};