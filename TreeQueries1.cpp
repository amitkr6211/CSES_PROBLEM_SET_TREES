#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007

int main(){
    int n,q;
    cin>>n>>q;

    // vector<int> v[n+1];
    
    int t=log2(n)+1;

    vector<vector<int>> dp(n+1,vector<int>(t,-1));

    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        dp[i][0]=x; //storing the parents
    }
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
        int x,k;
        cin>>x>>k;
        //kth parent

        while(k>0 and x!=-1){
            int jump=log2(k);
            int new_vert=dp[x][jump];
            // cout<<jump<<" "<<new_vert<<endl;
            int t=(int)(pow(2,jump)+0.5);
            // cout<<" kk k  "<<t<<endl;
            k-=(int)(pow(2,jump)+0.5);

            x=new_vert;
            // cout<<k<<" "<<x<<endl;
        }
        cout<<x<<" ";
    }
    return 0;
}