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
int arr[50005]={0};int n,k;
int num(int length) {
    int cnt = 0, end = -1;
    for (int i = 0; i < n; i++) {
        if (end < arr[i]) {
            cnt++;
            end = arr[i] + length;
        }
        if (cnt > k) return 0;
    }
    return 1;
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int l = 1, r = 1e10, mid = (l + r) / 2;

    while (l < r) {
        mid = (l + r) / 2;
        if (!num(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l;
}
signed main(void)
{ac;
  solve();
  return 0;
}