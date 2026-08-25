class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;

        for(char ch:s) mp[ch]++;

        priority_queue<pair<char,int>> pq;

        for(auto & [ch,f]:mp){
            pq.push({ch,f});
        }
        string ans="";
        while(pq.size()>0){
            auto temp=pq.top();
            pq.pop();
            char ch=temp.first;
            int freq=temp.second;

            if(freq<=repeatLimit){
                ans.append(freq,ch);
            }
            else{
                ans.append(repeatLimit,ch);
                if(!pq.empty()){
                    auto temp2=pq.top();
                    pq.pop();
                    char ch2=temp2.first;
                    int freq2=temp2.second;

                    if(freq2==1){
                        ans.append(1,ch2);
                    }
                    else{
                        ans.append(1,ch2);
                        pq.push({ch2,freq2-1});
                    }
                    pq.push({ch,freq-repeatLimit});
                }
                else //2nd element doesnot exists
                    break;
            }
        }
        return ans;

    }
};