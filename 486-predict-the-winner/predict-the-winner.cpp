class Solution {
public:
    int helper(vector<int>&nums,int i,int j,bool turn){//it will take array as input and return the value of x-y x->p1 scor y p2 score
        if(i>j){
            return 0;
        }
        if (turn){
            int x=nums[i] + helper(nums,i+1,j,false);
            int y=nums[j] + helper(nums,i,j-1,false);

            return max(x,y);
        }
        else{
            int x=-1*nums[i] + helper(nums,i+1,j,true);
            int y=-1*nums[j] + helper(nums,i,j-1,true);

            return min(x,y);
        }
        
     }
    bool predictTheWinner(vector<int>& nums) {
        int ans=helper(nums,0,nums.size()-1,true);

        return ans>=0?true:false;
    }
};