class Solution {
public:
    int maxProduct(int n) {
        int max1=INT_MIN;
        int max2=INT_MIN;

        while(n!=0){
            int digit=n%10;
            if(max1<digit){
                max2=max1;
                max1=digit;
                // cout<<max1<<endl<<max2<<"\n----";
            }
            else if(max2<digit) max2=digit;

            n/=10;
        }

        return max1 * max2;
    }
};