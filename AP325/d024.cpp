#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
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
void solve() {
    int n, m;
    int room[200005] = {0}, key[20005] = {0};
    int pfx[200005] = {0};
    cin >> n >> m;
    cin >> room[0];
    pfx[0] = room[0];
    for (int i = 1; i < n; i++) {
        cin >> room[i];
        pfx[i] = pfx[i - 1] + room[i];
    }

    for (int i = 0; i < m; i++) cin >> key[i];
    int idx = 0;

    for (int i = 0; i < m; i++) {
        int look;
        if (idx == 0)
            look = key[i];
        else
            look = key[i] + pfx[idx];

        int pos = lower_bound(pfx + idx + 1, pfx + n, look) - pfx;
        if (pos == n) {
            look = key[i] - (pfx[n - 1] - pfx[idx]);
            pos = lower_bound(pfx, pfx + n, look) - pfx;
        }
        idx = pos;
    }
    cout << idx + 1;
}

signed main(void)
{ac;
  solve();
  return 0;
}