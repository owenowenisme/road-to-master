#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
#define pb push_back
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
int n,t,arr[100005][2]={0},dp[100005][2]={0};
int a,b;
void solve(){
    cin>>n>>arr[0][0];
    arr[0][1]=arr[0][0];
    rep(i,1,n+1)cin>>arr[i][0]>>arr[i][1];
    dp[1][0]=abs(arr[1][0]-arr[0][0]);
    dp[1][1]=abs(arr[1][1]-arr[0][0]);
    rep(i,2,n+1){
        dp[i][0]=min(abs(arr[i][0]-arr[i-1][0])+dp[i-1][0],abs(arr[i][0]-arr[i-1][1])+dp[i-1][1]);
        dp[i][1]=min(abs(arr[i][1]-arr[i-1][0])+dp[i-1][0],abs(arr[i][1]-arr[i-1][1])+dp[i-1][1]);
    }
    cout<<min(dp[n][0],dp[n][1]);
}
signed main(void){
    ac;
    solve();
    return 0;
}