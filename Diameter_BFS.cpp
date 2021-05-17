#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007

int bfs(vector<int> v[], int src, int &ans){
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
        if(cost>dist){
            dist=cost;
            ans=vert;
        }
        for(int i=0;i<(int)v[vert].size();i++){
            int new_vert=v[vert][i];
            if(new_vert==par)continue;
            q.push({vert,{new_vert,cost+1}});
        }
    }
    return dist; 
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
    int res= bfs(v,node_a,node_b);

    cout<<res<<endl;;
    return 0;
}