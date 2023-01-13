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
pair<int,int>pr[100005];
pair<double,int>pr2[100005];
void solve() {
    int n;
    cin >> n;
    int tmp = 0, ans = 0;
    for (int i = 0; i < n; i++) cin >> pr[i].first;
    for (int i = 0; i < n; i++) {
        cin >> pr[i].second;
        pr2[i].first = (double)pr[i].first / (double)pr[i].second;
        pr2[i].second = i;
    }
    sort(pr2, pr2 + n);
    for (int i = 0; i < n; i++) {
        ans += tmp * pr[pr2[i].second].second;
        tmp += pr[pr2[i].second].first;
    }
    cout << ans << '\n';
}
signed main(void)
{ac;
  solve();
  return 0;
}