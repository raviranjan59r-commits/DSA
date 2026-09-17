class Solution {
public:
    vector<int> st;
    void point_update(int i,int l,int r,int idx){
        if(l==r){
            st[i]=1;
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
    int get(int i,int l,int r,int start,int end){// it will return the no of common elements present in nums1 and nums2 
        if(l>end || r<start) return 0;

        if(start<=l && r<=end){
            return st[i];
        }
        int mid=l+(r-l)/2;

        return get(i*2+1,l,mid,start,end) + get(i*2+2,mid+1,r,start,end);
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();

        st.resize(4*n,0);
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }

        point_update(0,0,n-1,mp[nums1[0]]);

        long long ans=0;
        for(int i=1;i<n-1;i++){

            
            int idx=mp[nums1[i]];

            int left_common_count=get(0,0,n-1,0,idx-1);
            int left_uncommon_count=i-left_common_count;
            int element_after_idx_in_nums2=(n-1-idx);
            int right_common_count=element_after_idx_in_nums2-left_uncommon_count; 
            ans+=1LL * left_common_count*right_common_count;

            point_update(0,0,n-1,idx);
        }
        return ans;
    }
};