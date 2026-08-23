class Solution {
public:
    bitset<8> reverse(bitset<8> & b){
        bitset<8> c;

        for(int i=0;i<8;i++) c[i]=b[7-i];

        return c;
    }
    bool isPalindromic(string s) {
        // int i=0;
        int j=s.length()-1;

        for(int i=0;i<(j/2 +1);i++){
            bitset<8> a(s[i]);
            bitset<8> b(s[j-i]);
            bitset<8> rev=reverse(b);

            if(a!=rev) return false;
        }
        // if(j%2==0){
        //     bitset<8> a(s[j/2]);
        //     bitset<8> b=reverse(a);
        //     if(a!=b) return false;
        // }
        return true;
    }
};