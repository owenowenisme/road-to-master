#include <bits/stdc++.h>
#define ac                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first
#define S second
#define maxn 1e8
const double EPS = 1e-7;
using namespace std;
void debug_out() {
    cerr << "]\n" << flush;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H;
    if (sizeof...(T)) cerr << ", ";
    debug_out(T...);
}
#define debug(...)                                                     \
    cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; \
    debug_out(__VA_ARGS__)

void solve() {
}

signed main(void) {
    ac int t;
    int n, m;
    int a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        bool chessboard[n + 5][n + 5] = {0};
        bool flag = 0;
        vector<pair<int, int>> v;
        v.clear();
        int row[n + 5] = {0}, column[n + 5] = {0};
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            chessboard[a][b] = 1;
            row[a]++;
            column[b]++;
            if (row[a] > 2 || column[b] > 2) {
                flag = 1;
            }
        }
        if (m > n || flag)
            cout << "NO\n";
        else {
            int rowcounter0 = 0, rowcounter1 = 0, rowcounter2 = 0,
                colcounter2 = 0, colcounter1 = 0, colcounter0 = 0;
            for (int i = 1; i <= n; i++) {
                if (row[i] == 0) rowcounter0++;
                if (row[i] == 2) rowcounter2++;
                if (row[i] == 1) rowcounter1++;
                if (column[i] == 0) colcounter0++;
                if (column[i] == 1) colcounter1++;
                if (column[i] == 2) colcounter2++;
            }

            if (rowcounter1 == n && colcounter1 == n)
                cout << "NO\n";
            else if (rowcounter2 == 0 && colcounter2 == 0 ||
                     (rowcounter0 == rowcounter2 && rowcounter2 == colcounter0))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
