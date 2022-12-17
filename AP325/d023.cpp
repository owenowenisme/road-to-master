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
int height[200005]={0};int ans[200005]={0};
int n,k,w; pair<int,int> pii[200005];int idx=1;

void recu(int l, int r, int water) {
    if (water <= 0) return;
    if (r - l <= 1) {
        ans[l] = water;
        return;
    }
    pair<int, int> tmp;
    for (int i = idx + 1; i < n; i++) {
        if (pii[i].second >= l && pii[i].second < r) {
            tmp = pii[i];
            idx = i;
            break;
        }
    }
    if (water >= (r - l) * tmp.first) {
        for (int i = l; i < r; i++) ans[i] = water/(r-l);
        return;
    }
    if (k < tmp.second) {  // chosen's left
        if ((tmp.second - l) * tmp.first <= water) {
            for (int i = l; i < tmp.second; i++) ans[i] = tmp.first;
            recu(tmp.second, r, water - (tmp.second - l) * tmp.first);
            return;
        } else {
            recu(l, tmp.second, water);
            return;
        }
    } else {
        if ((r - tmp.second) * tmp.first <= water) {
            for (int i = tmp.second; i < r; i++) ans[i] = tmp.first;
            recu(l, tmp.second, water - (r - tmp.second) * tmp.first);
            return;
        } else {
            recu(tmp.second, r, water);
            return;
        }
    }
}
void solve() {
    cin >> n >> k >> w;
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        pii[i] = {height[i], i};
    }
    sort(pii, pii + n, greater<pair<int, int>>());
    recu(0, n - 1, w);
    for (int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
    cout<<'\n';
}
signed main(void) {
    ac;
    solve();
    return 0;
}