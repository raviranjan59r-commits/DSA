class Solution {
public:
    int minOperations(string s) {
        vector<int> freq(26,0);

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        // int count=0;
        vector<char> abc;

        for(int i=1;i<26;i++){
            if(freq[i]!=0){
                abc.push_back('a'+i);
            } 
        }
        abc.push_back('a');

        for(auto ele:abc) cout<<ele<<" ";

        int count=0;
        for(int i=0;i<abc.size()-1;i++){
            count+= (26-(abc[i]-abc[i+1]))%26;
        }

        // ans+=26-(s[i]-'a');

        return count;

    }
};