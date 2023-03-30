#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
#define pb push_back
//#define int long long
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
int pr[105]={0},weight[105]={0},dp[2][100005]={0};
void solve(){
    int n,w;cin>>n>>w;
    rep(i,1,n+1)cin>>weight[i];
    rep(i,1,n+1)cin>>pr[i];

    rep(i,1,n+1){
        rep(j,1,weight[i])
            dp[i%2][j]=dp[(i-1)%2][j];
        rep(j,weight[i],w+1)
            dp[i%2][j]=max(dp[(i-1)%2][j-weight[i]]+pr[i],dp[(i-1)%2][j]);
    } 
    cout<<dp[n%2][w];
}
signed main(void){
    ac;
    solve();
    return 0;
}