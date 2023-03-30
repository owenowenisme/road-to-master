#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
#define pb push_back
// #define int long long
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int dp[200005]={0},n,m,s,arr[105]={0},total=0,ans=1e9;;
void solve(){
    cin>>n>>m>>s;
    rep(i,1,n+1){
        cin>>arr[i];
        total+=arr[i];
    }
    int req=s-(m-total);
    if(req<=0){
        cout<<0;
        return;
    }
    rep(i, 1, n + 1) {
        for(int j =req;j>0;j--){
        if (dp[j] + arr[i] >= req)
            ans = min(dp[j] + arr[i], ans);
        if (arr[i] <= j) 
            dp[j] = max(dp[j - arr[i]] + arr[i], dp[j]);
        }
    }
    cout<<ans;
}
signed main(void){
    ac;
    solve();
    return 0;
}