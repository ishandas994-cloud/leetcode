class Solution {
public:
    bool bfs(int n,  vector<vector<int>>&adj, int source, int destination){
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            if(node == destination){
                return true;
            }
            for(int nei : adj[node]){
                if(!visited[nei]){
                    visited[nei]=true;
                    q.push(nei);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto edge :edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return bfs(n,adj,source,destination);
    }
};