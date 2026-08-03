class Solution {
public:
    int count =0;
int inversion(vector<int>& v1,vector<int>& v2){
    int i=0;//v1
    int j=0;//v2
    int count1=0;
    while(i<v1.size() && j<v2.size()){
        if((long long)v1[i]>(long long) 2 *v2[j]){
            count1+=v1.size()-i;
            j++;
        }
        else i++;
    }
    return count1;
}
void merge(vector<int>& v1,vector<int>& v2,vector<int>& res){
    int n1=v1.size();
    int n2=v2.size();
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(v1[i]<v2[j]) {
            res[k]=v1[i];
            i++;
        }
        else {
            res[k]=v2[j];
            j++;
        }
        k++;
    }
    if(i==n1){
        while(j<n2){
            res[k]=v2[j];
            j++;
            k++;
        }
    }
    else if(j==n2){
        while(i<n1){
            res[k]=v1[i];
            i++;
            k++;
        }
    }
}
void mergeSort(vector<int>&nums){
    int n=nums.size();
    if(n==1) return;
    int n1=n/2;
    int n2=n-n1;
    vector<int>v1(n1);
    vector<int>v2(n2);
    for(int i=0;i<n1;i++){
        v1[i]=nums[i];
    }
    for(int i=0;i<n2;i++){
        v2[i]=nums[i+n1];
    }
    mergeSort(v1);
    mergeSort(v2);
    //counting inversion
    count+=inversion(v1,v2);
    merge(v1,v2,nums);
    v1.clear();
    v2.clear();
}
    int reversePairs(vector<int>& nums) {
        //brute force
        mergeSort(nums);

        return count;
        
    }
};