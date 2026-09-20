class Solution {
public:
    long long t[51][101][51];
    int M=1e9+7;
    int solve(int size,int lastMax,int score,int n,int m,int k){
        if(size>n) return 0;
        if(size==n ){
            return score==k;
        }
        if(score>k) return 0;
        if(t[size][lastMax][score]!=-1) return t[size][lastMax][score];
        // choosing between 1 to m
        long long res=0;
        for(int i=1;i<=m;i++){
            long long take;
            if(i>lastMax){
                take=solve(size+1,i,score+1,n,m,k);
            }
            else{
                take=solve(size+1,lastMax,score,n,m,k);
            }

            res=(res+take)%M;
        }
        return  t[size][lastMax][score]=res;

    }
    int numOfArrays(int n, int m, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,0,0,n,m,k);
    }
};