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
int m,n,arr[205][205]={0},ans=0,tmp[205]={0};
void solve() {
    cin >> m >> n;
    rep(i, 1, m + 1) {
        rep(j, 1, n + 1) {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int p = 1; p <= m; p++) {
                tmp[p] = arr[p][i] - arr[p][j];
                if (tmp[p - 1] > 0) tmp[p] += tmp[p - 1];
            }
            ans = max(ans, tmp[m]);
        }
    }
    cout << ans;
}
signed main(void){
    ac;
    solve();
    return 0;
}