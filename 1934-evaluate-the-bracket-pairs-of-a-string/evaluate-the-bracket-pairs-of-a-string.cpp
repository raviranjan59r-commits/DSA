class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        
        string ans="";
        string curr="";
        stack<int> st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(mp.count(curr))
                    ans+=mp[curr];
                else ans+='?';
                curr="";
                st.pop();
            }
            else{
                if(st.empty()) ans+=s[i];
                else curr+=s[i];
            }
        }

        return ans;

    }
};