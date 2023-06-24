#include<bits./stdc++.h>
using namespace std;

void dfs(int currentnode, vector<vector<int>> &edges, int parent,int level,int &ans){

    // cout<<currentnode<<" ";
    
    for(auto neighbour: edges[currentnode]){
        if(neighbour!=parent){
            dfs(neighbour,edges,currentnode,level+1,ans);
        }
    }

    if(ans<level){
        ans = level;
    }
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> edges(n+1,vector<int>());
    // hum 0 bhi add karrhe h isliye total size of edges will be n+1
    // edges will be n

    for(int i=0; i<n; i++){
        int number; cin>>number;

        if(number==-1){
            edges[i+1].push_back(0);
            edges[0].push_back(i+1);
        }
        else{
            edges[i+1].push_back(number);
            edges[number].push_back(i+1);
        }
    }
    
    int ans = 0;
    dfs(0,edges,-2,0,ans);

    cout<<ans;
    return 0;
}