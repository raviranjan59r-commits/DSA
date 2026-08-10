class Solution {
public:
    int digitFrequencyScore(int n) {
        // unordered_map<int,int> freq;

        // while()
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
};