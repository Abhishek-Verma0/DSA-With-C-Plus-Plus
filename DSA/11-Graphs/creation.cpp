/***Graph is data structure which is combination of nodes and edges
 * types of graphs Directed and unidirected graphs 
 *   Weighted Graphs --- every edge has some weight
 * if weight not assigned to edges then for being safe we can assume 1 as weight
 * 
 * Path -- sequence of nodes each node occuring only at once 
 * Cyclic Graph -- If we get back to the starting node then graph is cyclic
 * Acyclic Graph -- If we dont get back to the starting node then graph is acyclic
 *  
 * 
 * 
 * to implement graph we can use two things Adjacency Matrix and Adjacency list 
 * 
 * Adj Matrix --- edges and vertices given 
 * in adj list we list all node along with which connections are available to each of them
 */ 


#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int> >adj;
    void addEdge(int u, int v, bool direction){
        // direction =0 undirected
        // direction =1 directed

        // create an edge form u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

};


int main(){
    int n;
    cout<<"Enter number of nodes :: ";
    cin>>n;
    int m;
    cout<<"Enter number of edges :: ";
    cin>>m;
    graph g;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        //creating undirected graph
        g.addEdge(u, v, 0);
    }
    //printing graph
    g.printAdjList();
    return 0;
}