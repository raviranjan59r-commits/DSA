class Solution {
public:
    int reverse(int n){
        int res=0;

        while(n!=0){
            int d=n%10;
            res*=10;
            res+=d;
            n/=10;
        }
        return res;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};