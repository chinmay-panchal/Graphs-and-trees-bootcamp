#include<bits./stdc++.h>
using namespace std;

void help(int currentnode, int cats,int m, unordered_map<int,bool>&M, vector<vector<int>> &edges,int parent,int &count){
    
    if(M[currentnode]==1 && m==0){
        return;
    }

    if(edges[currentnode].size()==1 && currentnode!=1){
        // this code doesn't work because root ki ek hi size h aur waha apanne 1+ kardiya 
        // cout<<currentnode<<" ";
        count++;
    }

    for(int neighbour: edges[currentnode]){

        int temp = 0;
        if(M[currentnode]==0){temp=cats;}
        else if(M[currentnode]==1){temp=m-1;}

        if(neighbour!=parent){
            help(neighbour,cats,temp,M,edges,currentnode,count);
        }
    }

}

int main(){
    int n; int m;
    cin>>n>>m;
    unordered_map<int,bool>M;
    for(int i=1; i<=n; i++){
        bool x; cin>>x;
        M[i]=x;
    }

    vector<vector<int>> edges(n+1,vector<int>());

    for(int i=0; i<n-1; i++){
        int x; int y;
        cin>>x>>y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // cout<<edges[1].size();
    int count = 0;

    help(1,m,m,M,edges,-2,count);
    cout<<count;
    return 0;
}