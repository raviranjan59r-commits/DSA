class Solution {
public:
    long long count=0;

    vector<long long> merge(vector<long long>&left,vector<long long>&right,int lower,int upper){
        int n=left.size();
        int m=right.size();

        int l=0;
        int r=0;

        // count valid pairs
        for(int j=0;j<m;j++){
            while(l<n && left[l]<right[j]-upper)
                l++;

            while(r<n && left[r]<=right[j]-lower)
                r++;

            count+=r-l;
        }

        // normal merge
        vector<long long> res;
        int i=0;
        int j=0;

        while(i<n && j<m){
            if(left[i]<=right[j]){
                res.push_back(left[i]);
                i++;
            }
            else{
                res.push_back(right[j]);
                j++;
            }
        }

        while(i<n){
            res.push_back(left[i]);
            i++;
        }

        while(j<m){
            res.push_back(right[j]);
            j++;
        }

        return res;
    }

    vector<long long> mergeSort(vector<long long>&nums,int lower,int upper){
        int n=nums.size();

        if(n<=1) return nums;

        int mid=n/2;

        vector<long long> left(nums.begin(),nums.begin()+mid);
        vector<long long> right(nums.begin()+mid,nums.end());

        left=mergeSort(left,lower,upper);
        right=mergeSort(right,lower,upper);

        return merge(left,right,lower,upper);
    }

    int countRangeSum(vector<int>& nums,int lower,int upper){
        vector<long long> prefix(nums.size()+1,0);

        for(int i=0;i<nums.size();i++)
            prefix[i+1]=prefix[i]+nums[i];

        mergeSort(prefix,lower,upper);

        return count;
    }
};