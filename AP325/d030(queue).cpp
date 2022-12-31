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
int n=0,l=0,cnt=0,high=0;queue<int> q;
struct {
    int pos;
    int h;
    int next;
    int prev;
    int alive = 0;
} tree[100005];
void init() {
    cin >> n >> l;
    tree[0].h = 1e+10;
    tree[0].pos = 0;
    tree[0].next = 1;
    tree[0].prev = -1;
    tree[n + 1].h = 1e+10;
    tree[n + 1].pos = l;
    tree[n + 1].next = -1;
    tree[n + 1].prev = n;
    for (int i = 1; i <= n; i++) cin >> tree[i].pos;
    for (int i = 1; i <= n; i++) cin >> tree[i].h;
    for (int i = 1; i <= n; i++) {
        tree[i].alive = 1;
        tree[i].next = i + 1;
        tree[i].prev = i - 1;
    }
}
bool cuttable(int i) {
    int left = tree[i].pos - tree[i].h;
    int right = tree[i].pos + tree[i].h;
    int s = tree[i].prev, t = tree[i].next;

    if (tree[i].alive == 0) return 0;
    if ((tree[s].pos <= left || tree[t].pos >= right)) {
        return 1;
    }

    return 0;
}
void remove(int i) {
    int s = tree[i].prev, t = tree[i].next;
    tree[s].next = t;
    tree[t].prev = s;
    tree[i].alive = 0;
    return;
}
void solve() {
    init();

    for (int i = 1; i <= n; i++) {
        if (cuttable(i)) {
            q.push(i);
            remove(i);
        }
    }

    while (!q.empty()) {
        cnt++;

        int i = q.front();
        high = max(high, tree[i].h);
        q.pop();
        if (cuttable(tree[i].prev)) {
            q.push(tree[i].prev);
            remove(tree[i].prev);
        }
        if (cuttable(tree[i].next)) {
            q.push(tree[i].next);
            remove(tree[i].next);
        }
    }
    cout << cnt << '\n' << high;
}
signed main(void) {
    ac;
    solve();
    return 0;
}