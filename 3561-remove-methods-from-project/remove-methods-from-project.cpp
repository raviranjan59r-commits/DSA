class Solution {
public:
    vector<vector<int>> create_adj(int n,vector<vector<int>>&edges){
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        return adj;
    }
    void DFS(vector<vector<int>> &adj,int node,vector<int>&visited,vector<int>&infected){
        visited[node]=true;
        infected[node]=1;

        for(int neigh:adj[node]){
            if(!visited[neigh]){
                DFS(adj,neigh,visited,infected);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj=create_adj(n,invocations);
        vector<int> visited(n,0);
        vector<int> infected(n,0);

        DFS(adj,k,visited,infected);
        
        vector<int> ans;
        //for each clean edge check it is connected to infected or not

        for(auto edge:invocations){
            int a=edge[0];
            int b=edge[1];

            if(!infected[a] && infected[b]){
                for(int i=0;i<n;i++){
                    ans.push_back(i);

                }
                return ans;
            }
        }

        for(int i=0;i<n;i++){
            if(!infected[i]) ans.push_back(i);
        }
        return ans;

    }
};