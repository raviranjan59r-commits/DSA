class Solution {
public:
    // static bool cmp(pair<char,int> a,pair<char,int> b){
    //     return a.first>b.first;
    // }
    int minimumPushes(string word) {
        int n=word.size();
        vector<int> freq(26,0);

        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),[](int a,int b){
            return a>b;
        });

        int ans=0;
        int count=0;
        int key=1;
        for(int i=0;i<26;i++){
            if(freq[i]==0) break;
            ans+=freq[i]*key;
            count++;
            if(count==8){
                count=0;
                key++;
            }
            
        }
        return ans;
    }
};