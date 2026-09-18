class Solution {
public:
    vector<int> st;
    vector<int> nums;
    void point_update(int i,int l,int r,int idx){
        if(l==r){
            nums[idx]=-1;
            st[i]=idx;
            return;
        }

        int mid=l+(r-l)/2;

        if(idx<=mid){
            point_update(i*2+1,l,mid,idx);
        }
        else{
            point_update(i*2+2,mid+1,r,idx);
        }

        int left=st[i*2+1];
        int right=st[i*2+2];

        if(nums[left]>=nums[right]){
            st[i]=left;
        }
        else{
            st[i]=right;
        }
    }

    void build(int i,int l,int r){
        if(l==r){
            st[i]=l;
            return;
        }

        int mid=l+(r-l)/2;

        build(i*2+1,l,mid);
        build(i*2+2,mid+1,r);

        int left=st[i*2+1];
        int right=st[i*2+2];

        if(nums[left]>=nums[right]){
            st[i]=left;
        }
        else{
            st[i]=right;
        }
    }

    int getMax(int i,int l,int r,int start,int end){
        if(l>end || r<start){
            return -1;
        }

        if(start<=l && r<=end){
            return st[i];
        }

        int mid=l+(r-l)/2;

        int left=getMax(i*2+1,l,mid,start,end);
        int right=getMax(i*2+2,mid+1,r,start,end);

        if(left==-1) return right;
        if(right==-1) return left;

        if(nums[left]>=nums[right]){
            return left;
        }
        else{
            return right;
        }
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // we can use a max segment tree and then use binary search to find the closest greter basket

        int n=fruits.size();

        nums=baskets;

        st.resize(4*n);
        build(0,0,n-1);

        for(int i=0;i<n;i++){
            int l=0;
            int r=n-1;

            while(l<r){
                int mid=l+(r-l)/2;

                int idx=getMax(0,0,n-1,0,mid);

                if(idx!=-1 && nums[idx]>=fruits[i]){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }

            int idx=getMax(0,0,n-1,0,l);

            if(idx!=-1 && nums[idx]>=fruits[i]){
                point_update(0,0,n-1,idx);
            }
        }

        int count=0;

        for(int i=0;i<n;i++){
            if(nums[i]!=-1){
                count++;
            }
        }

        return count;
    }
};