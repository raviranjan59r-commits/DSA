class RangeFreqQuery {
public:
    int n;
    vector<unordered_map<int,int>> arr;
    RangeFreqQuery(vector<int>& nums) {
        n=nums.size();
        arr.resize(4*n);
        build_st(nums,0,0,n-1);
    }
    void build_st(vector<int>&nums,int idx,int l,int r){
        if(l==r){
            arr[idx][nums[l]]=1;
            return;
        }
        int mid=(l+r)/2;
        build_st(nums,idx*2+1,l,mid);
        build_st(nums,idx*2+2,mid+1,r);
        arr[idx]=arr[idx*2+1];

        for(auto it:arr[idx*2+2]){
            arr[idx][it.first]+=it.second;
        }
    }
    int query2(int idx,int l,int r,int left,int right,int val){
        //case 1 complete overlap
        if(left<=l && right>=r) return arr[idx][val];
        //no overlap

        if(left>r || right<l) return 0;

        int mid=(l+r)/2;

        return query2(idx*2+1,l,mid,left,right,val) + query2(idx*2+2,mid+1,r,left,right,val);
    }
    int query(int left, int right, int value) {
        return query2(0,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */