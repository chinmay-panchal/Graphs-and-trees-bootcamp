#include<bits./stdc++.h>
using namespace std;

void dfs(int currentnode, vector<vector<int>> &edges, int parent){
    cout<<currentnode<<" ";

    for(auto neighbour: edges[currentnode]){ // auto k baad joh bhi hoga woh iterator nahi hoga woh value at iterator hoga 
        if(neighbour!=parent){ 
            // kyunki like 1 parent hoga 2 ka and 2 ka negubour bhi toh 1 hoga so 1 pehle hi print hogaya h and wapis print nahi karna
            // chahte so parent k equal hoga agar koi number toh hum use print nahi karenge kyunki woh already print hochuka hoga 

            dfs(neighbour, edges, currentnode);
        }
    }
}

void printedges(vector<vector<int>> &edges){
    for(int i=0; i<edges.size(); i++){
        for(auto value: edges[i]){
            // cout<<edges[i]<<endl; this is completely wrong kyunki pura vector exist karta h 
            cout<<"i = "<<i<<" values: "<<value<<endl;
        }
    }
}

void leveldfs(int currentnode, vector<vector<int>> &edges, int parent, vector<int> &level, int currentlevel){

    level[currentnode] = currentlevel;
    for(auto neighbour: edges[currentnode]){ 
        if(neighbour!=parent){ 
            leveldfs(neighbour, edges, currentnode,level,currentlevel+1);
        }
    }
}

void parentdfs(int currentnode, vector<vector<int>> &edges, int parent, vector<int>&parent1){

    parent1[currentnode]=parent;

    for(auto neighbour: edges[currentnode]){
        if(neighbour!=parent){ 
            parentdfs(neighbour, edges, currentnode,parent1);
        }
    }
}

void numberOfChildrendfs(int currentnode, vector<vector<int>> &edges, int parent,vector<int>&childrens){

    for(auto neighbour: edges[currentnode]){ 
        if(neighbour!=parent){ 
            childrens[currentnode]++;
            numberOfChildrendfs(neighbour, edges, currentnode,childrens);
        }
    }
}

void subtreedfs(int currentnode, vector<vector<int>> &edges, int parent,vector<int>&subtree){

    for(auto neighbour: edges[currentnode]){ 
        if(neighbour!=parent){ 
            subtreedfs(neighbour, edges, currentnode,subtree);
            subtree[currentnode]+=subtree[neighbour]; // neighbour ka aajayega recursion se 
        }
    }
    subtree[currentnode]++; // ek uska size toh hoga hi woh toh hamesha plus hoga 

    // or int subtreedfs karke function bannana h toh niche diya gaya code is also right
    
    // for(auto neighbour: edges[currentnode]){ 
    //     if(neighbour!=parent){ 
    //         subtree[currentnode]+=subtreedfs(neighbour, edges, currentnode,subtree);
    //     }
    // }
    // subtree[currentnode]++; 
    // return subtree[currentnode];
}

int main(){

    // in trees edges would always be equal to n-1
    // n = no. of nodes 

    int n; 
    cin>>n;

    vector<vector<int>> edges(n,vector<int>());

    // above 2d vectors represent node number * edges 
    // isme andar wale vector ki size fixed nahi h kyunki ek nodes k bohot sare neighbours hoskte h 

    for(int i=0; i<n-1; i++){ // n-1 isliye kyunki total n-1 edges rehti h
        int x; int y;
        cin>>x; cin>>y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // printedges(edges);

    // koi bhi parent dedo starting m fark nahi padta kyunki print hona hi h, but make sure aisa number hojoki tree m nahi h 
    // dfs(0,edges,-2);

    // vector<int> level(n,-1);
    // leveldfs(0, edges, -2, level, 0);
    // for(int i=0; i<level.size(); i++){
    //     cout<<i<<": "<<level[i]<<endl;
    // }

    // vector<int> parent(n,-1);
    // parentdfs(0,edges,-2,parent);

    // for(int i=0; i<parent.size(); i++){
    //     if(parent[i]<0){cout<<"no parent"<<endl;}
    //     else cout<<i<<": "<<parent[i]<<endl;
    // }

    // vector<int> childrens(n,0);
    // we can easily do it if its a root then simple return its adjacency size 
    // if it is non root then simple return its adjacency size -1 because ek parent hoga usme

    // for(int i=0; i<childrens.size(); i++){
    //     if(i==0){childrens[i]=edges[i].size();}
    //     else{childrens[i]=edges[i].size()-1;}
    // }

    // or by dfs 
    // numberOfChildrendfs(0,edges,-2,childrens);

    // for(int i=0; i<childrens.size(); i++){
    //     cout<<i<<": "<<childrens[i]<<endl;
    // }

    vector<int> subtree(n,0);
    subtreedfs(0,edges,-1,subtree);
    for(int i=0; i<subtree.size(); i++){
        cout<<i<<": "<<subtree[i]<<endl;
    }
    return 0;
}

