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
    int n, k;
    cin >> n >> k;
    int arr[200005] = {0};
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int total = 0;
    int tail = 1, head = 1;
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (total + arr[i] > k) {
            tail = i - 1;
            break;
        }
        total += arr[i];
        ans = total;
    }
    cnt++;
    for (int i = tail + 1; i <= n; i++) {
        total += arr[i];
        while (total > k) {
            total -= arr[head];
            head++;
        }
        if (total > ans) {
            ans = total;
            cnt = 1;
        } else if (total == ans)
            cnt++;
    }
    cout << ans << '\n' << cnt;
}
signed main(void)
{ac;
  solve();
  return 0;
}