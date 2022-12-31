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
int fastpow(int x, int y, int p) {
    if (y < 1) return 1;
    if (y & 1) {
        int tmp = fastpow(x, y >> 1, p)% p;
        return ((tmp * tmp % p) * x) % p;
    } else {
        int tmp = fastpow(x, y >> 1, p) % p;
        return (tmp * tmp) % p;
    }
}
void solve() {
    int n, p, tmp;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cout << fastpow(tmp, p - 2, p) << ' ';
    }
}
signed main(void) {
    ac;
    solve();
    return 0;
}