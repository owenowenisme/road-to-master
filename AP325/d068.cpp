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
int n,arr[100005]={0},dp[100005]={0};
void solve() {
    cin >> n;
    rep(i, 0, n) { cin >> arr[i]; }
    if (n == 1) {
        cout << arr[0];
        return;
    }
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = min(dp[1], dp[0]) + arr[2];
    rep(i, 3, n) { dp[i] = arr[i] + min({dp[i - 1], dp[i - 2], dp[i - 3]}); }
    cout << min(dp[n - 1], dp[n - 2]);
}
signed main(void){
    ac;
    solve();
    return 0;
}