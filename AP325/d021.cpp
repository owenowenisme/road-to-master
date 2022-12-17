#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
//#define int long long
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
    int k;
    while (cin >> k) {
        int ans = 0;
        int m, n, tmp;
        cin >> m >> n;
        int pscol[n + 1000][m + 2] = {0};  // ps for column
        int psall[n + 1000][m + 2] = {0};
        vector<set<int>> v(m + 2);
        set<int> st;
        st.insert(0);
        for (int i = 0; i <= m; i++) v[i].insert(0);
        for (int i = 1; i <= n; i++) {
            st.clear();
            st.insert(0);
            for (int j = 1; j <= m; j++) {
                cin >> tmp;
                pscol[i][j] = pscol[i][j - 1] + tmp;
                psall[i][j] = psall[i - 1][j] + pscol[i][j];

                for (int q = 1; q <= j; q++) {
                    tmp = *(v[q].lower_bound(psall[i][j] - k));
                    if (psall[i][j] - tmp <= k)
                        ans = max(ans, psall[i][j] - tmp);
                }

                tmp = *(st.lower_bound(pscol[i][j] - k));
                if (pscol[i][j] - tmp <= k) ans = max(ans, pscol[i][j] - tmp);
                st.insert(pscol[i][j]);
                v[j].insert(psall[i][j]);
            }
        }
        cout << ans;
    }
}
signed main(void) {
    ac;
    solve();
    return 0;
}
