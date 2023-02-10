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
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int arr[100005]={0};
int sub(int l, int r) {
    if (l >= r) {
        return max((int)0, arr[l]);
    }
    int m = (l + r) / 2;
    int a = max(sub(l, m), sub(m + 1, r));
    int tmp = 0, lcross = 0, rcross = 0;
    for (int i = m; i >= l; i--) {
        tmp += arr[i];
        lcross = max(tmp, lcross);
    }
    int tmpp = 0;
    for (int i = m + 1; i <= r; ++i) {
        tmpp += arr[i];
        rcross = max(tmpp, rcross);
    }
    return max(a, lcross + rcross);
}
void solve(){
    int n,tmp,ans=0;cin>>n;
    rep(i,0,n)
        cin>>arr[i];
    cout<<sub(0,n-1);
}
signed main(void){
    ac;
    solve();
    return 0;
}