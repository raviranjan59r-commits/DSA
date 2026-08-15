class Solution {
public:
    int minOperations(string s) {
        vector<int> freq(26,0);

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=1;i<26;i++){
            if(freq[i]!=0){
               char ch='a'+i;
               return 26 - (ch - 'a');
            } 
        }
        return 0;

    }
};