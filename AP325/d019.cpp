#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int  long long
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int n,p;int num[50];set<int>a,b;int ans=-1000000;
int counter=0;
void recu(set<int> *st, int sum, int idx, int end) {
    if (sum > p) return;
    if (idx == end) {
        (*st).insert(sum);
        if (sum <= p && p - sum < p - ans) ans = sum;
        return;
    }
    recu(st, sum + num[idx], idx + 1, end);
    recu(st, sum, idx + 1, end);

    return;
}

void solve() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> num[i];
    recu(&a, 0, 0, n / 2);
    recu(&b, 0, n / 2, n);
    for (auto it:a) {
        int tmp = p - it;
        auto look = b.upper_bound(tmp);  //原本超白癡用upperbound(b.begin(),b.end(),tmp)超慢甚至會tle要注意！
        look--;
        int get = (*look);
        if (get <= p && p - (it + get) < p - ans) ans = get + it;
    }
    cout << ans;
}
signed main(void) {
    ac;
    solve();
    return 0;
}
