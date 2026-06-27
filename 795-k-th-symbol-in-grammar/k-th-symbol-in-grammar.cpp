class Solution {
public:
    int f(int n,int k){
        if(n==1 && k==1) return 0;

        //even change
        if(k%2==0) return !f(n-1,k/2);

        return f(n-1,k/2+1);

    }
    int kthGrammar(int n, int k) {
        
        return f(n,k);
    }
};