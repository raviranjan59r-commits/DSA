class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string s=countAndSay(n-1);
        string ans="";
        int i=0;
        int count=0;

        while(i<s.length()){
            char ch=s[i];
            count=0;

            while(i<s.length() && ch==s[i]){
                 count++;
                 i++;
            }

            ans+=to_string(count)+ch;
        }
        // ans+=to_string(count) + s[i-1];

        return ans;
    }
};