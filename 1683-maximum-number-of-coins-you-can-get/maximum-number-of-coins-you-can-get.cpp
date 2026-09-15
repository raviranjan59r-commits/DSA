class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int n=piles.size();
        int ans=0;
        for(int i=1;i<2*n/3;i+=2){
            ans+=piles[i];
        }
        return ans;
        // 1 2 2 4 7 8 
        // 9 8 7 6 5 4 3 2 1

        //
    }
};