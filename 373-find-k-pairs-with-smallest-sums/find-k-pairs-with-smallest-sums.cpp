class Solution {
public:
    using pp = pair<int,pair<int,int>> ;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        priority_queue< pp,vector<pp>,greater<pp> > pq;

        //put the smallest element in the heap
        pq.push({nums1[0]+nums2[0],{0,0}});


        set<pair<int,int>> visited;

        visited.insert({0,0});
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int i=temp.second.first;
            int j=temp.second.second;

            ans.push_back({nums1[i],nums2[j]});
            if(ans.size()==k) return ans;

            if(j+1 < nums2.size() && !visited.count({i,j+1})){
                pq.push({nums1[i] + nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
            if(i+1 < nums1.size() && !visited.count({i+1,j})){
                pq.push({nums1[i+1] + nums2[j],{i+1,j}});
                visited.insert({i+1,j});
            }
            
        }
        return ans;
    }
};