#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007
int dp[200002];
int solve(vector<int> v[], int src){
    if(dp[src]!=-1){
        return dp[src];
    }
    int ans=1;
    for(int i=0;i<(int)v[src].size();i++){
        int t=solve(v,v[src][i]);
        ans+=t;
    }
    return dp[src]=ans;
}
int main(){
    int n;
    cin>>n;

    vector<int> v[n+1];
    memset(dp,-1,sizeof(dp));
    for(int i=2;i<=n;i++){
        int t;
        cin>>t;
        v[t].push_back(i);
    }
    //graph formed

    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        int t=solve(v,i);
        ans[i]=t;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]-1<<" ";
    }
    cout<<endl;
    return 0;
}