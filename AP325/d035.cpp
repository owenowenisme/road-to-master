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
int n,arr[200005];
unordered_set<int>st;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int head = 1, tail = 0;
    for (int i = 1; i <= n; i++) {
        if (st.find(arr[i]) != st.end()) {
            tail = i - 1;
            break;
        }
        st.insert(arr[i]);
    }
    int ans = tail - head + 1;
    while (tail < n) {
        tail++;
        while (st.find(arr[tail]) != st.end()) {
            st.erase(arr[head]);
            head++;
        }
        st.insert(arr[tail]);
        ans = max(tail - head + 1, ans);
    }
    cout << ans << '\n';
}
signed main(void) {
    ac;
    solve();
    return 0;
}