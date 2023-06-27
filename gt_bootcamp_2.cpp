#include<bits./stdc++.h>
using namespace std;

// 27-06-2023 gym jane se pehle yeh bfs aur ancestor wala question complete kiya 
// bas dhyan yeh rakhna h ki apan edges likhte wakt u-- and v-- kardete h 
// aur edges[currentnode] likhna bhul jate h dfs k wakt 
// aur map mai yeh agar auto funtion nahi hota toh auto ki jagah kya likhte yeh doubt h 
// aaj shashank,sid,neet,himanshu bro gaye wapis saroda

// In-Out time trick if x is an ancestor of y 
// implement it by yourself // ancestor descendent problem 

void bfs(vector<vector<int>> &edges, int n){
    int root = 0;
    // vector<int> bfs_traversal;
    queue<int>q;
    vector<bool> visited(n,false);

    q.push(root);
    visited[root]=true;

    while(!(q.empty())){
        int currentnode = q.front();
        cout<<q.front()<<" ";
        q.pop();
        for(int neighbour : edges[currentnode]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
            }            
        }
    }
}

void dfsAncestor(int currentnode, vector<vector<int>> &edges, int parent,unordered_map<int,int>&in, unordered_map<int,int>&out,int &time){
    // X in time < Y in time < Y out time < X out time
    // cout<<currentnode<<" ";
    in[currentnode]=time++;
    for(auto neighbour: edges[currentnode]){ // auto k baad joh bhi hoga woh iterator nahi hoga woh value at iterator hoga 
        if(neighbour!=parent){ 
            // kyunki like 1 parent hoga 2 ka and 2 ka negubour bhi toh 1 hoga so 1 pehle hi print hogaya h and wapis print nahi karna
            // chahte so parent k equal hoga agar koi number toh hum use print nahi karenge kyunki woh already print hochuka hoga 

            dfsAncestor(neighbour, edges, currentnode,in,out,time);
        }
    }
    out[currentnode]=time++;
}

void dfs(int current, vector<vector<int>>&edges, int parent, vector<int> &disX){
    // this question is used for diameter 

    if(parent!=-1){
        disX[current]=disX[parent]+1; // matlab prev node ki dist + 1 
    }

    // cout<<current<<" "<<"parent = "<<parent<<" "<<" "<<"dis[current]= "<<disX[current]<<endl;

    for(int neighbour: edges[current]){
        if(neighbour!=parent){
            dfs(neighbour,edges,current,disX);
        }
    }
}

int main(){
    int n; 
    cin>>n;

    vector<vector<int>> edges(n,vector<int>());
    for(int i=0; i<n-1; i++){
        int x; int y;
        cin>>x; cin>>y;

        x--; y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // Question 3: ancestor h k nahi batao

    unordered_map<int,int> in,out; 
    int time = 0;
    dfsAncestor(0,edges,-1,in,out,time);

    for(auto i: in){
        cout<<i.first<<" in time = "<<i.second<<endl;
    }

    for(auto i: out){
        cout<<i.first<<" out time = "<<i.second<<endl;
    }

    // Question 1: bfs ka code batao
    // bfs(edges,n);

    // Question 2: diameter batao 
    // int x = 0; // 0 yaha par 1 h total nodes are 0 to n-1 // randomly kuch bhi rakh skte h 
    // vector<int> disX(n,0);
    // dfs(x,edges,-1,disX);

    // int y = 0; // yeh bhi koi bhi rakh sakte h 0 to n-1 hame max length chahiye from x
    // for(int i=0; i<n; i++){
    //     if(disX[i]>disX[y]){
    //         y = i;
    //     }
    // }

    // cout<<"y = "<<y<<endl;

    // vector<int> disY(n,0);
    // // cout<<endl;
    // dfs(y,edges,-1,disY);

    // int z = 0; // max dis from y which will be our diameter
    // for(int i=0; i<n; i++){
    //     // cout<<"y = "<<disY[i]<<" ";
    //     if(disY[i]>disY[z]){
    //         z = i;
    //     }
    // }

    // cout<<"z = "<<z<<endl;
    // cout<<disY[z]<<endl; // yehe diameter ki distance 

    // ab y is one end point and x is one end point of the diamter 
    // if we have to find the max distance from a particular node then 
    // hame z se ek baar dfs karleneka ofcourse y hi answer aayega z se toh
    // par hame woh nahi chahiye hame bas z se every node ka distance chahiye 
    // uske liye ek vector banado and dfs start karo 

    // vector<int> disZ(n,0);
    // dfs(z,edges,-1,disZ);

    // // now hame ek end point y se sari nodes tak ka distance malum h 
    // // aur hame ek end point z se sari nodes tak ka distance malum h 

    // // # from every node the farthest node will be one of the end points of the diameter
    // // proof yad kardeneka bhidu algo ka 

    // for(int i=0; i<n; i++){
    //     // now from every node print kardenge 
    //     cout<<max(disY[i],disZ[i])<<" ";
    // }

    return 0;
}