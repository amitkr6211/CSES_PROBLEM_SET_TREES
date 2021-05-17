#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007
// int dp[200002];
int ans=0;
int solve(vector<int> v[], int src, int par){
    int res=0;
    // cout<<"src "<<src<<endl;
    int a=INT_MIN;
    int b=INT_MIN;
    for(int i=0;i<(int)v[src].size();i++){
        if(v[src][i]==par)continue;
        int t=solve(v,v[src][i],src);
        // cout<<t<<endl;
        if(t>a)
        {
            b=a;
            a=t;
        }
        else if(t>b)
        {
            b=t;
        }
    }
    // cout<<a<<" "<<b<<endl; 
    if(a==INT_MIN and b==INT_MIN){
        //leaf node
        ans=max(ans,1);
        return 1;
    }
    if(b==INT_MIN){
        //one child
        ans=max(ans,a+1);
        return 1+a;
    }
    else{
        ans=max(ans,1+a+b);
        return max(a,b)+1;
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

    int dia=solve(v,1,-1);
    ans=max(dia,ans)-1;
    cout<<ans<<endl;
    return 0;
}