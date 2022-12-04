#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first
#define S second
#define maxn 1e8
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int ans=0;int chess[15][15] = {0};
int queen(int n, int k, int p[]) {
    if (k >= n) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] != -1) tmp += chess[i][p[i]];
        }
        ans = max(tmp, ans);
        return 1;
    }
    int valid[15] = {0};
    fill_n(valid, sizeof(valid)/sizeof(int), 1);
    for (int i = 0; i < k; i++) {
        if (p[i] != -1) {
            valid[p[i]] = 0;
            int j = k - i + p[i];  //斜率＝1
            if (j < n) valid[j] = 0;
            j = i - k + p[i];  //斜率＝-1
            if (j >= 0) valid[j] = 0;
        }
    }
    p[k] = -1;
    queen(n, k + 1, p);
    for (int i = 0; i < n; i++) {
        if (valid[i]) {
            p[k] = i;
            queen(n, k + 1, p);
        }
    }
    return 0;
}
void solve() {
    int p[15] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> chess[i][j];
    }
    queen(n, 0, p);
    cout << ans;
}
signed main(void) {
    ac;
    solve();
    return 0;
}