#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first
#define S second
const int maxn = 1e8;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
void solve() {
    int tmp = 0;
    int m, n;
    int ans = 0;
    cin >> m >> n;
    int tar = (1 << m) - 1;
    string s;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> s;
        tmp = 0;
        for (int j = 0; j < s.length(); j++) 
            tmp |= (1 << (s[j] - 'A'));

        auto t = st.find(tmp ^ tar);
        if (t != st.end()) {
            ans++;
            st.erase(t);
        } 
        else
            st.insert(tmp);
    }
    cout << ans << '\n';
}
signed main(void) {
    ac;
    solve();
    return 0;
}