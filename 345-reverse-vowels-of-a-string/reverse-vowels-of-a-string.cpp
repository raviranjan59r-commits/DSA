class Solution {
public:
    bool isVowel(char ch){
        string s="aeiouAEIOU";
        int idx=-1;
        idx=s.find(ch);

        return idx>=0;
    }
    string reverseVowels(string s) {
        stack<char> st;

        for(char ch:s) {
            if(isVowel(ch)) st.push(ch);
        }

        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=st.top();
                st.pop();
            }
        }
        return s;
    }
};