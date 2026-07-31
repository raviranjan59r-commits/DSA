class Solution {
public:
    // static bool cmp(pair<char,int> a,pair<char,int> b){
    //     return a.first>b.first;
    // }
    int minimumPushes(string word) {
        int n=word.size();
        int freq[26]={0};

        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }

        vector<pair<char,int>> v;

        for(int i=0;i<26;i++){
            v.push_back({'a'+i,freq[i]});
        }

        sort(v.begin(), v.end(),
         [](const auto &a, const auto &b) {
             return a.second > b.second;
         });

        int ans=0;
        int count=0;
        int key=1;
        for(int i=0;i<26;i++){
            char ch=v[i].first;
            int fre=v[i].second;
            if(fre==0) continue;
            cout<<"character: "<<ch<<"->"<<"freq: "<<fre<<endl;
            ans+=key*fre;
            count++;

            if(count==8){
                key++;
                count=0;
            }
        }
        return ans;
    }
};