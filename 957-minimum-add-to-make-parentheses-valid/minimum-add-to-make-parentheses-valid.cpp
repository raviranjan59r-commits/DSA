class Solution {
public:
    int minAddToMakeValid(string s) {
        int depth=0;

        int count1=0;

        for(auto ch :s){
            if(ch=='(') depth++;
            else{
                depth--;
                if(depth<0){
                    count1++;
                    depth=0;
                }
            }
        }
        count1+=depth;
        return count1;
    }
};