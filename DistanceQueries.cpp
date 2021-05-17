#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007


void dfs(vector<int> v[], vector<int> &parent, vector<int> &depth, int src, int cur_depth, int par){
    parent[src]=par;
    depth[src]=cur_depth;

    for(int i=0;i<(int)v[src].size();i++){
        int new_vert=v[src][i];

        if(new_vert==par)continue;
        dfs(v,parent,depth,new_vert,cur_depth+1,src);
    }
}
int LCA(int a, int b, vector<int> &depth , vector<vector<int>> &dp){
    int da=depth[a];
    int db=depth[b];

    if(db>da){
        swap(a,b);
    }
    int d=abs(da-db);
    int ans=d;
    // dth ancestor of a
    while(d>0){
        int jump=log2(d);
        int new_vert=dp[a][jump];
        // cout<<jump<<" "<<new_vert<<endl;
        // int t=(int)(pow(2,jump)+0.5);
        // cout<<" kk k  "<<t<<endl;
        d-=(int)(pow(2,jump)+0.5);

        a=new_vert;
        // cout<<k<<" "<<x<<endl;
    }
    //now a and b are at the same level
    // cout<<a<<" "<<b<<endl;  
    if(a==b){
        return ans;
    }
    if(dp[a][0]==dp[b][0]){
        return ans+2;//2 extra edges
    }
    int N=depth.size();
    int t=log2(N-1);
    // cout<<t<<endl;
    // int vert=0;
    while(t>=0)
    {
        // cout<<t<<endl;
        int ta=dp[a][t];
        // vert=ta;
        int tb=dp[b][t];
        // cout<<ta<<" "<<tb<<endl;
        if(ta==-1){
            t--;
            continue;
        }
        else if(ta==tb){
            t--;
            continue;
        }
        else{
            // break;
            int jump=(int)(pow(2,t)+0.5);
            ans+=2*jump;
            a=ta;
            b=tb;
        }
    }
    return ans+2;
}

int main(){
    int n,q;
    cin>>n>>q;

    vector<int> v[n+1];
    
    int t=log2(n)+1;

    vector<vector<int>> dp(n+1,vector<int>(t,-1));
    
    vector<int> depth(n+1,0);
    vector<int> parent(n+1,-1);

    for(int i=0;i<n-1;i++){
        int src,dest;
        cin>>src>>dest;
        v[src].push_back(dest);
        v[dest].push_back(src);
    }
    dfs(v,parent,depth,1,0,-1);
    // fill the dp array 
    for(int i=1;i<=n;i++){
        dp[i][0]=parent[i];
    }

    for(int j=1;j<t;j++){ 
        for(int i=1;i<=n;i++){
            int x=dp[i][j-1];
            if(x==-1){
                continue;
            }
            dp[i][j]=dp[x][j-1];
        }
    }
    //table formed
    cout<<"formed"<<endl;
    return 0;
    //take queries 
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b,depth,dp)<<" ";
    }
    return 0;
}