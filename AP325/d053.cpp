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
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; i++) pq.push(0);
    int arr[200005] = {0};
    for (int i = 0; i < n; i++) cin >> arr[i];
    int tmp;
    for (int i = 0; i < n; i++) {
        tmp = pq.top() + arr[i];
        pq.pop();
        pq.push(tmp);
    }
    while (pq.size() > 1) pq.pop();
    cout << pq.top() << '\n';
}
signed main(void) {
    ac;
    solve();
    return 0;
}