#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
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
int arr[100005]={0};int tmp[100005]={0};
int n;
int sub(int l, int r) {
    if (l >= r) {
        return 0;
    }
    int m = (l + r) / 2;
    int ans = sub(l, m) + sub(m + 1, r), k = 0, j = m + 1;
    for (int i = l; i <= m; ++i) {
        while (j <= r && arr[j] < arr[i]) {
            ans += (m - i + 1);
            tmp[k++] = arr[j++];
        }
        tmp[k++] = arr[i];
    }
    for (int i = l; i < j; ++i) {
        arr[i] = tmp[i - l];
    }
    cout << '\n';
    return ans;
}
void solve() {
    cin >> n;
    rep(i, 0, n) cin >> arr[i];
    cout << sub(0, n - 1);
}
signed main(void){
    ac;
    solve();
    return 0;
}