#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-5;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
struct point {
    double x;
    int idx;
};
typedef point point;
vector<pair<int, int>> v;
vector<point> v2;
point tmp;

int a, b;
bool cmp(point p, point q) {
    if (abs(p.x - q.x) < EPS) return 1;
    return p.x < q.x;
}
void solve() {
    int n, m;
    cin >> n >> m;
    v.pb({-1e10, -1e10});
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        v.pb({a, b});
    }
    sort(v.begin(), v.end());
    tmp.idx = 1;
    tmp.x = -1e10;
    v2.pb(tmp);
    for (int i = 2; i <= n; i++) {
        while (i < n && v[i].first == v[i + 1].first)i++;  // dealing with parallel lines
        double px = ((double)(v[i].second - v[v2.back().idx].second)) /
                    ((double)(v[v2.back().idx].first - v[i].first));
        while (px < v2.back().x) {
            v2.pop_back();
            px = ((double)(v[i].second - v[v2.back().idx].second)) /
                 ((double)(v[v2.back().idx].first - v[i].first));
        }
        tmp.idx = i;
        tmp.x = px;
        v2.pb(tmp);
    }
    int ans = 0, k;

    for (int i = 0; i < m; i++) {
        cin >> k;
        int a = lower_bound(v2.begin(), v2.end(), (point){k, 0}, cmp) -v2.begin() - 1;
        int now = v2[a].idx;
        ans += v[now].first * k + v[now].second;
    }
    cout << ans << '\n';
}
signed main(void) {
    ac;
    solve();
    return 0;
}