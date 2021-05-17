#include<bits/stdc++.h>
using namespace std;

#define ll long long 
// #define mod 1000000007

ll int dp[200002];
ll int solve(vector<int> v[], int src, int par){
    if(dp[src]!=-1){
        return dp[src];
    }
    ll int ans=1;
    for(int i=0;i<(int)v[src].size();i++){
        if(v[src][i]==par)continue;
        ll int t=solve(v,v[src][i],src);
        ans+=t;
    }
    return dp[src]=ans;
}

ll int bfs(vector<int> v[], int src){
    //farthest node from src
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    ll int dist=0;
    
    while(!q.empty()){
        pair<int,pair<int,int>> p=q.front();
        q.pop();
        ll int vert=p.second.first;
        ll int cost=p.second.second;
        // cout<<vert<<" hh "<<cost<<endl;
        ll int par=p.first;
        // dist=(dist%mod+cost%mod)%mod;
        dist+=cost;

        for(int i=0;i<(int)v[vert].size();i++){
            int new_vert=v[vert][i];
            if(new_vert==par)continue;
            q.push({vert,{new_vert,cost+1}});
        }
    }
    return dist;
}

void dfs(vector<ll int> &ans, vector<int> v[], int src, int par){
    //find its ans
    ll int N=ans.size()-1;
    ll int x=dp[src]-1;
    // ans[src]=((ans[par]%mod+(N-2)%mod)%mod-2*x+mod)%mod;
    ans[src]=ans[par]+(N-2)-2*x;

    for(int i=0;i<(int)v[src].size();i++){
        if(v[src][i]==par)continue;
        dfs(ans,v,v[src][i],src);
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
    
    memset(dp,-1,sizeof(dp));
    ll int cost=bfs(v,1);
    vector<ll int> ans(n+1,0);
    ans[1]=cost;
    // cout<<cost<<endl;
    for(int i=1;i<=n;i++){
        solve(v,i,0);
    }
    for(int i=0;i<(int)v[1].size();i++){
        dfs(ans,v,v[1][i],1);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}