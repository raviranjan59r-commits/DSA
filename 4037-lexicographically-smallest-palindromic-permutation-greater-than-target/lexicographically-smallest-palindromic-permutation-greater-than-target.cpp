class Solution {
public:
    bool checkPalindrome(vector<int> &freq, bool isodd){
        int odd=0;

        for(int i=0;i<26;i++){
            if(freq[i]%2) odd++;
        }

        if(isodd)
            return odd == 1;
        else
            return odd == 0;
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26,0);
        int n=s.length();
        bool isodd=(n%2);

        for(char ch:s) freq[ch-'a']++;

        if(!checkPalindrome(freq,isodd)) return "";

        char odd_char='A';

        for(int i=0;i<26;i++){
            if(freq[i]%2){
                odd_char=i+'a';
                break;
            }
        }

        string ans="";

        for(int i=0;i<target.size()/2;i++){
            char ch=target[i];

            if(freq[ch-'a']>1){
                ans+=ch;
                freq[ch-'a']-=2;
            }
            else{
                //try higher character
                for(char alpha = ch+1 ; alpha <= 'z' ; alpha++ ){
                    if(freq[alpha-'a']>1){
                        //then we have found the answer
                        ans+=alpha;
                        freq[alpha-'a']-=2;

                        // construct the ans from remaining palindrome 

                        for(int i=0;i<26;i++){
                            while(freq[i]>=2){
                                ans+='a'+i;
                                freq[i]-=2;
                            }
                        }
                        string rev=ans;
                        reverse(rev.begin(),rev.end());

                        if(isodd) ans=ans+ odd_char +rev;
                        else ans=ans+rev;

                        return ans;
                    }
                }
                //after trying higher character you didnt get the result then do backtracking

                // if(isodd){
                //     if(odd_char>target[n/2]){
                //         string rev=ans;
                //         reverse(rev.begin(),rev.end());
                //         return ans=ans+ odd_char +rev;
                //     }
                // }
                //to be wriiten
                for(int i=ans.size()-1;i>=0;i--){
                    char ch1=ans[i];
                    freq[ch1-'a']+=2;
                    ans.pop_back();

                    //try character greater than prev char

                    for(char alpha=ch1+1;alpha<='z';alpha++){
                        if(freq[alpha-'a'] >= 2) {
                            //we found the ans
                            ans+=alpha;
                            freq[alpha-'a']-=2;

                            // construct the ans from remaining palindrome 

                            for(int i=0;i<26;i++){
                                while(freq[i]>=2){
                                    ans+='a'+i;
                                    freq[i]-=2;
                                }
                            }
                            string rev=ans;
                            reverse(rev.begin(),rev.end());

                            if(isodd) ans=ans+ odd_char +rev;
                            else ans=ans+rev;

                            return ans;
                        }
                    }

                }
                //after backtracking you didnt find the ans
                return "";
            }
        }
        //both target and s have the same first half
       // construct the palindrome from current ans
        string candidate = ans;

        if(isodd)
            candidate += odd_char;

        string rev = ans;
        reverse(rev.begin(), rev.end());

        candidate += rev;

        // If candidate itself is already greater than target
        if(candidate > target)
            return candidate;

        for(int i=ans.size()-1;i>=0;i--){
            char ch1=ans.back();
            freq[ch1-'a']+=2;
            ans.pop_back();

            //try character greater than prev char

            for(char alpha=ch1+1;alpha<='z';alpha++){
                if(freq[alpha-'a'] >= 2) {
                    //we found the ans
                    ans+=alpha;
                    freq[alpha-'a']-=2;

                    // construct the ans from remaining palindrome 

                    for(int i=0;i<26;i++){
                        while(freq[i]>=2){
                            ans+='a'+i;
                            freq[i]-=2;
                        }
                    }
                    string rev=ans;
                    reverse(rev.begin(),rev.end());

                    if(isodd) ans=ans+ odd_char +rev;
                    else ans=ans+rev;

                    return ans;
                }
            }

        }
        return "";
    }
};