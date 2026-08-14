class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();

        unordered_map<int,int> freq;
        int i=0;
        int j=0;
        int len=-1;
        while(i<n && j<n){
            while(j<n && freq[s[j]]<2){
                freq[s[j]]++;
                len=max(len,j-i+1);
                j++;
            }
            while(freq[s[j]]==2) {
                freq[s[i]]--;
                i++;
            }
        }
        return len;
    }
};