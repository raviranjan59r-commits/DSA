class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        int ones=0;

        string ans="";

        while(j<n){
            if(s[j]=='1') ones++;

            while(ones>k || s[i]=='0'){
                if(s[i]=='1') ones--;
                i++;
            }
            if(ones==k){
                string temp=s.substr(i,j-i+1);
                if(ans.empty() || ans.length()>temp.length() ||(ans.length()==temp.length() && temp<ans)){
                    ans=temp;
                }
            }
            j++;
        }
        return ans;
    }
};