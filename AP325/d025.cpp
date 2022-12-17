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
    int n, k, tmp;
    cin >> n;
    int root = 0, ans = 0;
    int parent[100005] = {0}, deg[100005] = {0};
    int seq[100005] = {0}, height[100005] = {0};
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        if (k == 0) 
            q.push(i);
        
        deg[i] = k;
        for (int j = 0; j < k; j++) {
            cin >> tmp;
            parent[tmp] = i;
        }
    }

    int idx = 1;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        seq[idx] = tmp;
        idx++;
        deg[parent[tmp]]--;
        if (deg[parent[tmp]] == 0) q.push(parent[tmp]);
    }
    for (int i = 1; i <= n; i++)
        height[parent[seq[i]]] =max(height[parent[seq[i]]], height[seq[i]] + 1);
    for (int i = 1; i <= n; i++) ans += height[i];
    cout << seq[n] << '\n' << ans;
}
signed main(void) {
    ac;
    solve();
    return 0;
}