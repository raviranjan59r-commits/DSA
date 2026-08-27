class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char,int> mp;

        for(char ch:s){
            mp[ch]++;
        }
        string ans="";
        for(char ch:target){
            if(mp[ch]>0){
                ans+=ch;
                mp[ch]--;
            }
            else{
                for(char alpha=ch+1;alpha<='z';alpha++){
                    if(mp[alpha]>0){
                        ans+=alpha;
                        mp[alpha]--;

                        for(auto &[c,f]:mp){
                            ans.append(f,c);
                        }
                        return ans;
                    }
                }
                //backtracking

                for(int j=ans.size()-1;j>=0;j--){
                    mp[target[j]]++;
                    ans.pop_back();

                    for(char alpha=target[j]+1 ; alpha<='z';alpha++){
                        if(mp[alpha]>0){
                            ans+=alpha;
                            mp[alpha]--;

                            for(auto &[c,f]:mp){
                                ans.append(f,c);
                            }
                            return ans;
                        }
                    }
                }
                return "";
            }
        }
        // both contain the same letters
        if(next_permutation(target.begin(),target.end()))
            return target;
        return "";
    }
};