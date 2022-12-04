#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first
#define S second
#define maxn 1e8
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int n,arr[30];int ans=0;
void recu(int idx, int mul, int k) {
    if (idx == n-1) {
        if (mul % 10009 == 1) ans++;
        if((mul*arr[idx]%10009==1))ans++;
        return;
    }

    if (k) {
        mul *= arr[idx];
        mul %= 10009;
        recu(idx + 1, mul, 1);
        recu(idx + 1, mul, 0);
    } else {
        recu(idx + 1, mul, 1);
        recu(idx + 1, mul, 0);
    }
    return;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    recu(0, 1, 1);
    recu(0, 1, 0);

    cout << ans / 2 - 1;
}
signed main(void) {
    ac;
    solve();
    return 0;
}