#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007

//depth of each node

void bfs(vector<int> &depth, vector<int> v[]){
    depth[1]=0;

    queue<pair<int,int>> q;
    q.push({1,0});

    while(!q.empty()){
        pair<int,int> p=q.front();
        depth[p.first]=p.second;
        q.pop();

        for(int i=0;i<(int)v[p.first].size();i++){
            q.push({v[p.first][i],p.second+1});
        }
    }
}
int LCA(int a, int b, vector<int> &depth , vector<vector<int>> &dp){
    int da=depth[a];
    int db=depth[b];

    // cout<<da<<" "<<db<<endl;
    if(db>da){
        swap(a,b);
    }
    int d=abs(da-db);

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
        return a;
    }
    if(dp[a][0]==dp[b][0]){
        return dp[a][0];
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
            a=ta;
            b=tb;
        }
    }
    return dp[a][0];

}
int main(){
    int n,q;
    cin>>n>>q;

    vector<int> v[n+1];
    
    int t=log2(n)+1;

    vector<vector<int>> dp(n+1,vector<int>(t,-1));
    
    vector<int> depth(n+1,0);
    vector<int> child(n+1,-1);

    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        dp[i][0]=x; //storing the parents
        v[x].push_back(i);
    }
    bfs(depth,v);
    // fill the dp array 

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

    //take queries 
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b,depth,dp)<<" ";
    }
    return 0;
}