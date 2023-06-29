#include<bits./stdc++.h>
using namespace std;

// question says that ki 
// 1. aise paths banao ki koi bhi do path aap choose karo toh common ek vertex aani chaiye  
// 2. agar koi path m apanne jitni bhi edge leli woh kisi aur path m nahi aani cahiye
// 3. vertex aaye toh chalega par edge sirf 1 hi path m aani chaiye aur path can be of 1 edge as well
// 4. trick yehe ki root to leaf sab print kardo

void help(vector<vector<int>> &edges, int n){
    int count = 0;
    int root = 0;
    
    vector<int>leaf;
    for(int i=1; i<=n; i++){
        if(edges[i].size()>2){
            root = i;
            count++;

            // root yeh hogi agar matlab degree greater then 2 h 
        }
        if(count>1){
            // agar aisi do nodes h jinka degree 2 se zyada h toh impossible hoga decomposition
            // kyunki ek rehi jayega
            cout<<"No";
            return;
        }
        if(edges[i].size()==1){
            // matlab leaf node h woh push kardo vector m
            leaf.push_back(i);
        }
    }

    if(count==1){

        // matlab ek hi root h aur sari leaf k sath jodi banake print kardo 
        cout<<"Yes"<<endl;
        cout<<leaf.size()<<endl;
        for(int i=0; i<leaf.size(); i++){
            cout<<root<<" "<<leaf[i]<<endl;
        }
    }
    else{ // skewed tree h so 1st node se last node ek hi path hoga
        cout<<"Yes"<<endl;
        cout<<"1"<<endl;
        cout<<leaf[0]<<" "<<leaf[1];
    }

}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> edges(n+1,vector<int>());

    for(int i=0; i<n-1; i++){
        int x; int y;
        cin>>x>>y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    if(n==2){
        // do hi nodes h toh ek hi path and yes 
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        cout<<1<<" "<<2;
    }

    else{
        help(edges,n);
    }
    return 0;
}