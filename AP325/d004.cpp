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
int arr[50005],n,k;
int ans=0;
int foo(int begin, int end, int mid) {//
    int tmp = 0;
    for (int i = begin; i < mid; i++) {
        tmp += (mid - i) * arr[i];
    }
    for (int i = end; i > mid; i--) {
        tmp += (mid - i) * arr[i];
    }
    return tmp;
}
int lever(int begin, int end, int counter) {//implement with binary search
    if (end - begin < 2 || counter >= k) return 0;
    int l = begin + 1, r = end - 1;
    if (l != r) {
        while (l < r) {
            int m = (l + r) / 2;
            if (foo(begin, end, m) < 0)
                l = m + 1;
            else
                r = m;
        }
    }

    if (abs(foo(begin, end, l - 1)) <= abs(foo(begin, end, l)) &&l - 1 != begin)l--;
    return arr[l] + lever(begin, l - 1, counter + 1) +
           lever(l + 1, end, counter + 1);
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    cout << lever(1, n, 0);
}
signed main(void) {
    ac;
    solve();
    return 0;
}