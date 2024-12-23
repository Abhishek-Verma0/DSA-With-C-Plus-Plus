/** BFS-  Breadth First Search
 *  
 */


#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int >>adj;
    void addEdge(int u,int v, bool dir){
        adj[u].push_back(v);
        if(dir==0){
            adj[v].push_back(u);
        }
    }

    void bfs(int startNode){
        queue<int>q;
        unordered_map<int,bool>visited;
    vector<int> result;

    visited[startNode]=true;
    q.push(startNode);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        result.push_back(node);

        for(auto i : adj[node]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }

    for(int i :result){
        cout<<i<<" ";
    }
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
    
    // Perform BFS traversal starting from node 0
    cout << "BFS Traversal starting from node 0:" << endl;
    g.bfs(0);

    return 0;
}
