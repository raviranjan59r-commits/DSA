class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // score = sum of square of digits
        string ans="";

        while(num--){
            if(sum>=10){
                ans+='9';
                sum-=9;
            }
            else{
                ans+=sum+'0';
                sum=0;
            }
        }
        if(sum==0) return ans;
        return "";
    }
};