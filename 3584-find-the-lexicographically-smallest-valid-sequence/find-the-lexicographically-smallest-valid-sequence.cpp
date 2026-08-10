class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n=word1.length();
        int j=word2.length()-1;

        vector<int> matched_chars(n,0);
        int count=0;
        for(int k=n-1;k>=0;k--){
            if(j>=0 && word1[k]==word2[j]){
                j--;
                count++;
            }
            matched_chars[k]=count;
        }

        bool can_change=true;
        vector<int> ans;
        j=0;
        for(int i=0;i<n;i++){
            if(j==word2.size()) return ans;
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else{
                if(can_change ){
                    if((i+1) < n && matched_chars[i+1]>=(word2.length() - j -1 )){
                        ans.push_back(i);
                        j++;
                        can_change=false;
                    }
                }
            }
            if(j==word2.size()) return ans;
        }
        return {};

    }
};