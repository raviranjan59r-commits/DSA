class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        int key=1;
        while(n>8){
            ans+=8*key;
            key++;
            n-=8;
        }
        ans+=key*n;

        return ans;
    }
};