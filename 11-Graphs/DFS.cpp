


#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u,int v,bool dir){
        adj[u].push_back(v);
        if(dir==0){
            adj[v].push_back(u);
        }
    }

    void dfs(int u, unordered_map<int,bool>& visited){
        visited[u]=true;
        // unordered_map<int ,list<int>>visited;
        for(auto i : adj[u]){
            if(!visited[i]){
                dfs(i,visited);
            }
        }
        void dfsTraversal(int startNode);
            unordered_map<int ,bool>visited;
            cout<<"DFS Trssversal  starting node "<<startNode<<" : ";
                dfs(startNode, visited);
                cout<<endl;
        
    }
};


int main() {
    graph g;
    int vertices, edges;

    // Input: number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    // Input: edge details (u, v) for each edge
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);  // Assuming undirected graph (dir=0)
    }

    // Perform DFS traversal starting from node 0
    g.dfsTraversal(0);

    return 0;
}