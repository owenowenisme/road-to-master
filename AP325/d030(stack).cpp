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
int tree[100005]={0}, height[100005];stack<int> st;
void solve() {
    int n, l, cnt = 0, high = 0;
    cin >> n >> l;
    tree[0] = 0;
    tree[n + 1] = l;
    height[0] = 1e+10;
    height[n + 1] = 1e+10;
    for (int i = 1; i <= n; i++) cin >> tree[i];
    for (int i = 1; i <= n; i++) cin >> height[i];
    st.push(0);
    for (int i = 1; i <= n; i++) {
        if (tree[i] - height[i] >= tree[st.top()] ||
            tree[i] + height[i] <= tree[i + 1]) {
            cnt++;
            high = max(high, height[i]);
            while (tree[st.top()] + height[st.top()] <= tree[i + 1]) {
                cnt++;
                high = max(high, height[st.top()]);
                st.pop();
            }
        } else {
            st.push(i);
        }
    }
    cout << cnt << '\n' << high;
}
signed main(void) {
    ac;
    solve();
    return 0;
}