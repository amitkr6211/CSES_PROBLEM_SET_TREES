#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007
int dp[200002];
// int ans=0;
int solve(vector<int> v[], int src, int par){
    if(dp[src]!=-1){
        return dp[src];
    }
    int ans=0;
    for(int i=0;i<(int)v[src].size();i++){
        if(v[src][i]==par)continue;
        //src to v[src][i];
        int nex_vert=v[src][i];
        int res=1;
        //child of src 
        for(int j=0;j<(int)v[src].size();j++){
            if(v[src][j]==par or v[src][j]==nex_vert){
                continue;
            }
            int t=solve(v,v[src][j],src);
            res+=t;
        }
        //child of next vert
        for(int j=0;j<(int)v[nex_vert].size();j++){
            if(v[nex_vert][j]==src){
                continue;
            }
            int t=solve(v,v[nex_vert][j],nex_vert);
            res+=t;
        }
        ans=max(ans,res);
    }
    return dp[src]=ans;
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
    if(v[1].size()==n-1 and n!=1){
        cout<<1<<endl;
        return 0;
    }
    int ans=solve(v,1,-1);
    // ans=max(dia,ans);
    
    cout<<ans<<endl;
    return 0;
}