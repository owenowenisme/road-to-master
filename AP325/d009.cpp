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
int ans=1e+10;int arr[20][20];
void recu(int up, int down, int left, int right, int total) {
    if (up >= down && left >= right) {
        ans = min(ans, total);
        return;
    }
    if (total > ans) return;

    int tmp, tmp0 = 0, tmp1 = 0;
    if (up <= down) {
        for (int i = left; i <= right; i++) {
            if (arr[up][i] == 0)
                tmp0++;
            else
                tmp1++;
        }
        tmp = min(tmp0, tmp1);
        recu(up + 1, down, left, right, total + tmp);
    }
    if (down >= up) {
        tmp0 = 0, tmp1 = 0;
        for (int i = left; i <= right; i++) {
            if (arr[down][i] == 0)
                tmp0++;
            else
                tmp1++;
        }
        tmp = min(tmp0, tmp1);
        recu(up, down - 1, left, right, total + tmp);
    }
    if (left <= right) {
        tmp0 = 0, tmp1 = 0;
        for (int i = up; i <= down; i++) {
            if (arr[i][left] == 0)
                tmp0++;
            else
                tmp1++;
        }
        tmp = min(tmp0, tmp1);
        recu(up, down, left + 1, right, total + tmp);
    }

    if (left <= right) {
        tmp0 = 0, tmp1 = 0;
        for (int i = up; i <= down; i++) {
            if (arr[i][right] == 0)
                tmp0++;
            else
                tmp1++;
        }
        tmp = min(tmp0, tmp1);
        recu(up, down, left, right - 1, total + tmp);
    }
    return;
}
void solve() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
    }
    recu(0, m - 1, 0, n - 1, 0);
    cout << ans;
}
signed main(void) {
    ac;
    solve();
    return 0;
}