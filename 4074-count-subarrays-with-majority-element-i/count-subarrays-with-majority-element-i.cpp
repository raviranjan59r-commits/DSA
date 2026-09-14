class Solution {
public:
    vector<int> st;
    vector<int> nums;
    int tar;
    void build_tree(int i,int l,int r){
        if(l==r){
            st[i] = nums[l]==tar?1:0;
            return;
        }
        int mid=l+(r-l)/2;
        build_tree(2*i+1,l,mid);
        build_tree(2*i+2,mid+1,r);

        st[i]=st[2*i+1] + st[2*i + 2];
    }
    int get(int i,int l,int r, int start, int end){
        //no overlap
        if(l>end || r<start) return 0;
        //complete overlap
        if(start<=l && r<=end) return st[i];
        //partial overlap
        int mid=l+(r-l)/2;

        return get(i*2+1,l,mid,start,end) + get(i*2+2,mid+1,r,start,end);
    }
    int countMajoritySubarrays(vector<int>& v, int target) {
        nums=v;
        int n=nums.size();
        tar=target;
        st.resize(4*n);
        build_tree(0,0,n-1);
        // form all the subarrys and keep count of those which ave majority element is target
        int total_count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len=j-i+1;
                int count=get(0,0,n-1,i,j);
                if(count>len/2) total_count++;
            }
        }
        return total_count;
    }
};