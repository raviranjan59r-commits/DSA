class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>9*n) return -1;
        if(s==0) return 0;
        int ans=0;

        while(n--){
            int digit;
            if(s>9){
                s=s-9;
                digit=9;
            }
            else{
                digit=s;
                s=0;
            }

            ans*=10;
            ans+=digit;
        }

        return ans;
    }
};