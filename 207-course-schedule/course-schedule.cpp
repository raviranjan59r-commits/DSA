class Solution {
public:
    bool khans_algo(vector<vector<int>> & adj){
        vector<int> indegree(adj.size(),0);
        int count=0;

        for(auto v:adj){
            for(auto ele:v){
                indegree[ele]++;
            }
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
           count++;

            for(auto neigh:adj[node]){
                indegree[neigh]--;

                if(indegree[neigh]==0) q.push(neigh);

            }
        }

        return adj.size()==count;

    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return khans_algo(adj);
    }
};