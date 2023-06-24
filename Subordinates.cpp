#include<bits/stdc++.h>
using namespace std;

// spcae complexity basically o(n+e) isliye kyunki usse zyada space nahi lega 
// n = no. of nodes and e = no. of edges = n-1;
// suppose n=2, e=n-1; total 3 and adjacency will take space of 2 (1-2 and 2-1) matlab O(N+E-1) hota h 1 ko ignore kiya h

void dfs(int currentnode, vector<vector<int>> &edges, int parent, vector<int>&subordinates){
    
    for(int neighbour: edges[currentnode]){
        if(parent!=neighbour){
            dfs(neighbour,edges,currentnode,subordinates);
            subordinates[currentnode]+=subordinates[neighbour];
        }
    }
    subordinates[currentnode]++;
}

int main(){
    int n;
    cin>>n;

    // n+1 isliye kyunki 1 se n tak jarha h 
    vector<vector<int>> edges(n+1,vector<int>());

    for(int i=2; i<=n; i++){
        int number; cin>>number;
        edges[i].push_back(number);
        edges[number].push_back(i);
    }

    vector<int> subordinates(n+1,0);
    dfs(1,edges,-2,subordinates);

    // simple h subtree size - 1;

    for(int i=1; i<=n; i++){
        // 1 se isliye kyunki 0 hoga hi nahi 
        cout<<subordinates[i]-1<<" ";
    }

    return 0;
}