#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007

void bfs(vector<int> v[], int src, int &ans){
    //farthest node from src
    
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    int dist=0;
    ans=src;
    while(!q.empty()){
        pair<int,pair<int,int>> p=q.front();
        q.pop();
        int vert=p.second.first;
        int cost=p.second.second;
        int par=p.first;
        if(cost>dist)ans=vert;

        for(int i=0;i<(int)v[vert].size();i++){
            int new_vert=v[vert][i];
            if(new_vert==par)continue;
            q.push({vert,{new_vert,cost+1}});
        }
    }
}
void BFS(vector<int> v[], int src, vector<int> &res){
    //farthest node from src
    
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    // int dist=0;
    
    while(!q.empty()){
        pair<int,pair<int,int>> p=q.front();
        q.pop();
        int vert=p.second.first;
        int cost=p.second.second;
        int par=p.first;
        res[vert]=cost;

        for(int i=0;i<(int)v[vert].size();i++){
            int new_vert=v[vert][i];
            if(new_vert==par)continue;
            q.push({vert,{new_vert,cost+1}});
        }
    }
}
int main(){
    int n;
    cin>>n;

    vector<int> v[n+1];
    for(int i=0;i<n-1;i++){
        int src, dest;
        cin>>src>>dest;
        v[src].push_back(dest);
        v[dest].push_back(src);
    }
    //graph formed
    

    int node_a=1;
    bfs(v,1,node_a);
    int node_b;
    bfs(v,node_a,node_b);

    vector<int> dist_a(n+1,0);
    vector<int> dist_b(n+1,0);
    BFS(v,node_a,dist_a);
    BFS(v,node_b,dist_b);

    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        ans[i]=max(dist_a[i],dist_b[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}