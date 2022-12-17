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
typedef pair<int,int> pii;
const int p=(1e+9)+9;
pii mul(pii a, pii b) {
    return {(a.first * b.first + ((a.second * b.second) << 1)) % p,
            (a.first * b.second + a.second * b.first) % p};
}

pii recu(pii x, int y) {
    pii ans = {1, 0};
    if (y >= 1) {
        pii tmp = recu(x, y / 2);
        if (y % 2)
            ans = mul((mul(tmp, tmp)), x);
        else
            ans = mul(tmp, tmp);
    }
    ans = {ans.first, ans.second};
    return ans;
}

void solve() {
    int x, y, n;
    while (cin >> x >> y >> n) {
        pii tmp = {x, y};
        pii ans = recu(tmp, n);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}
signed main(void) {
    ac;
    solve();
    return 0;
}