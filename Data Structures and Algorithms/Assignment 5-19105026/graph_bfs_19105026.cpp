#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int src,vector<bool> &vis){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        int front = q.front();
        cout<<front<<' ';
        q.pop();
        for(auto it: adj[front]) {
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
            }
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cout<<"Enter the number of nodes in graph: ";
    
    cin>>n;
    cout<<endl;
    vector<int> adj[n+1];
    vector<bool> vis(n+1,0);
    int edges;
    cout<<"Enter the noumber of edges the graph will have: ";
    
    cin>>edges;
    cout<<endl;
    cout<<"enter the links from one node to another(directed graph)"<<endl;
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        // adj[b].push_back(a);
    }
    cout<<"Enter the source node: ";
    int src;
    cin>>src;
    cout<<endl;
    cout<<"BFS traversal"<<endl;
    bfs(adj,src,vis);
    // cout<<"BFS traversal"<<endl; 
    // bfs(adj,src);


}