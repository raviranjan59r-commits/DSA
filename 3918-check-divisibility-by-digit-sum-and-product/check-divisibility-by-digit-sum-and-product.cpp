class Solution {
public:
    int sum_product(int n){
        int sum=0;
        int product=1;

        while(n!=0){
            sum+=n%10;
            product*=n%10;
            n/=10;
        }
        return sum+product;
    }
    bool checkDivisibility(int n) {
        
        return !(n % sum_product(n));
    }
};