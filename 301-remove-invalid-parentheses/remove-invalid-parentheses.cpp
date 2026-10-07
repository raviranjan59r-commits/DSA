class Solution {
public:
    unordered_set<string> st;
    int n;
    void solve(string & s,int i,int removal,string &temp){
        //base case
        if(i==s.length()){
            if(removal==n && !isValid(temp)){
                st.insert(temp);
            }
            return;
        }
        //take 
        temp+=s[i];
        solve(s,i+1,removal,temp);
        temp.pop_back();
        //skip
        if(removal<n) solve(s,i+1,removal+1,temp);

    }
    int isValid(string s){
        int depth=0;
        int minRemovals=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') depth++;
            else if(s[i]==')'){
                depth--;
                if(depth<0) {
                    minRemovals++;
                    depth=0;
                }
            }
        }
        minRemovals+=depth;
        return minRemovals;
    }
    vector<string> removeInvalidParentheses(string s) {
        
        n=isValid(s);
        string temp="";
        solve(s,0,0,temp);

        vector<string> ans;

        for(auto ele:st) ans.push_back(ele);

        return ans;
    }
};