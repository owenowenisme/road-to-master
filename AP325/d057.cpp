#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false), cin.tie(0)
#define int long long
using namespace std;
int p[100005] = {0};
void solve() {
    int n;
    cin >> n;
    int ans = 0, tmp;
    for (int i = 0; i < n; ++i) cin >> p[i];
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        ans += tmp;
        ans -= p[i] * (n - i);
    }

    cout << ans;
}
signed main(void)
{ac;
  solve();
  return 0;
}