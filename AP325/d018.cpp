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
unordered_map<int, int> a, b;
int num[50], n, p;
int fastpow(int x, int y) {
    if (y < 1) return 1;
    if (y & 1) {
        int tmp = fastpow(x, y >> 1) % p;
        return ((tmp * tmp % p) * x) % p;
    } 
    int tmp = fastpow(x, y >> 1) % p;
    return (tmp * tmp) % p;
    
}
int modinverse(int x) { return fastpow(x, p - 2); }
void recu(unordered_map<int, int> *mp, int idx, int mul, int end) {
    if (idx == end) {
        (*mp)[mul]++;
        return;
    }
    recu(mp, idx + 1, (mul * num[idx]) % p, end);
    recu(mp, idx + 1, mul, end);
}
void solve() {
    int ans = 0;
    cin >> n >> p;

    for (int i = 0; i < n; i++) cin >> num[i];
    recu(&a, 0, 1, n / 2);
    recu(&b, n / 2, 1, n);
    a[1]--;
    b[1]--;
    ans += a[1] + b[1];
 
    for (auto q : a) {
        debug(q.first);
        ans += b[modinverse(q.first)] * q.second;
    }
    debug(a.size());
    cout << ans << '\n';
}
signed main(void) {
    ac;
    solve();
    return 0;
}