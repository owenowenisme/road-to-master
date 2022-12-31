#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first
#define S second
const int maxn=1e5+5;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
struct sword{
    double ratio;
    int time;
    int work;
};

typedef sword sword;
bool cmp(sword a,sword b){
    return a.ratio>b.ratio;
}
vector<sword> v(maxn);

void solve() {
    int n;
    cin >> n;
    sword tmp;
    for (int i = 0; i < n; i++) {
        cin >> v[i].time;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].work;
        v[i].ratio = (double)v[i].work / (double)v[i].time;
    }
    sort(v.begin(), v.end(), cmp);
    int ans = v[0].time * v[0].work;
    for (int i = 1; i < n; i++) {
        debug(v[i].ratio);
        v[i].time += v[i - 1].time;
        ans += v[i].time * v[i].work;
    }
    cout << ans;
}
signed main(void)
{ac;
  solve();
  return 0;
}