class Solution {
public:
    bool one_group(unordered_set<int> & s){
            //for left group
            if(s.count(2)==0 && s.count(3)==0 && s.count(4)==0 && s.count(5)==0){
                return true;
            }

            if(s.count(6)==0 && s.count(7)==0 && s.count(4)==0 && s.count(5)==0){
                return true;
            }

            if(s.count(6)==0 && s.count(7)==0 && s.count(8)==0 && s.count(9)==0){
                return true;
            }

            return false;


    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;

        for(auto &v:reservedSeats){
            if(v[1]==1 || v[1]==10) continue;
            mp[v[0]].insert(v[1]);
        }

        int count=0;

        count+=(n-mp.size())*2;// 2 groups

        cout<<count<<" ";

        for(auto s:mp){
            cout<<"abc ";
            count+=one_group(s.second);
        }

        return count;

    }
};