class Solution {
public:
    int f(vector<int>&freq,int pos){
        if(pos==3){//base case
            //return no of even numbers that are left
            int count=0;
            for(int i=0;i<9;i+=2){
                if(freq[i]>0) count++;
            }
            return count;
        }
        int ans=0;
        for(int i=0;i<10;i++){// fix the second digit pos
            if(freq[i]<=0) continue;
            freq[i]--;

            ans+=f(freq,pos+1);

            freq[i]++;
        }
        return ans;
    }
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);

        for(int digit:digits){
            freq[digit]++;
        }

        int ans=0;

        for(int i=1;i<10;i++){//fix the first digit pos
            if(freq[i]<=0) continue;
            freq[i]--;
            ans+=f(freq,2);
            freq[i]++;
        }
        return ans;
    }
};