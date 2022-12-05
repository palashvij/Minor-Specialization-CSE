#include <bits/stdc++.h>
using namespace std;


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
    cout<<"Graph representation"<<endl;
    for(int i=0;i<=n;i++){
        cout<<i<<": ";
        for(auto it:adj[i]){
            cout<<it<<", ";
        }
        cout<<endl;
    }
    // cout<<"BFS traversal"<<endl; 
    // bfs(adj,src);


}