#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
#define pb push_back
#define int long long
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
int dp[505][505]={0};int tmp=0,ans=0;
void solve(){
    string a,b;
    cin>>a>>b;
    int al=a.length(),bl=b.length();
    for(int i=1;i<=al;i++){
        for(int j=1;j<=bl;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=max(dp[i-1][j-1],(long long)0)+8;
            }
            else{
                dp[i][j]=max(max(dp[i-1][j],dp[i][j-1])-3,(long long)0);
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]-5);
            }
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;

}
signed main(void){
    ac;
    solve();
    return 0;
}