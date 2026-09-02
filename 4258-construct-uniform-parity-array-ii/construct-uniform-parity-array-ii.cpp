class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallest_even=-1;
        int smallest_odd=-1;

        for(int num:nums1){
            if(num%2){
                //odd
                if(smallest_odd==-1){
                    smallest_odd=num;
                }else{
                    smallest_odd=min(smallest_odd,num);
                }
            }
            else{
                //even
                if(smallest_even==-1){
                    smallest_even=num;
                }
                else{
                    smallest_even=min(smallest_even,num);
                }
            }
        }
        if(smallest_even==-1 || smallest_odd==-1) return true;

        if((smallest_even-smallest_odd)>=1) return true;

        return false;
    }
};