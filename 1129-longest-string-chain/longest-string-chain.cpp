class Solution {
public:
    int t[1001][1001];
    bool isPredecessor(string a,string b){
        int n=a.length();
        int m=b.length();

        if(n!=m-1) return false;

        int i=0;
        int j=0;
        bool diff=false;
        while(i<n){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                if(!diff){
                    diff=true;
                    j++;
                }
                else{
                    return false;
                }
            }
        }
        return true;

    }
    int solve(vector<string>& words,int i,int prevIdx){
        if(i>=words.size()){
            return 0;
        }
        if(prevIdx!=-1 && t[i][prevIdx]!=-1) return t[i][prevIdx];
        int skip=solve(words,i+1,prevIdx);

        int take=0;

        if(prevIdx==-1 || isPredecessor(words[prevIdx],words[i])){
            take=1+solve(words,i+1,i);
        }
        
        if(prevIdx!=-1){
            t[i][prevIdx]=max(skip,take);
        }
        return max(skip,take);
    }
    int longestStrChain(vector<string>& words) {

        sort(words.begin(),words.end(),[](string a,string b){
            if(a.length()!=b.length()) return a.length()<b.length();

            return a<b;
        });

        memset(t,-1,sizeof(t));
        return solve(words,0,-1);
    }
};