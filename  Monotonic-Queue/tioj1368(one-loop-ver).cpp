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

void solve() {
    int n;
    while (cin >> n) {
        int arr[100005] = {0}, sfx[100005] = {0};

        stack<pair<int, int>> stleft, stright;
        int k[100005][2] = {0};

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sfx[i] = sfx[i - 1] + arr[i];
        }
        arr[n + 1] = -1;
        sfx[n + 1] = sfx[n];

        stleft.push({0, -1});  // first index second val
        stright.push({n + 1, -1});

        for (int i = 1; i <= n + 1; i++) {
            while (stleft.top().second > arr[i]) {
                k[stleft.top().first][1] = i - 1;//被移除時便已同時決定右邊界，因此無需再開一次迴圈計算右邊界
                stleft.pop();
            }
            k[i][0] = stleft.top().first;
            stleft.push({i, arr[i]});
        }

        int left, right;

        int ansl = 0, ansr = 1e+7, ans = 0;

        for (int i = 1; i <= n; i++) {
            int left = k[i][0], right = k[i][1];

            if (ans ==max(ans,(sfx[right] - sfx[left]) *arr[i])) {  //根據題意心情指數一樣時先輸出起點小的，若再次相同再輸出終點小的
                ans = max(ans, (sfx[right] - sfx[left]) * arr[i]);

                if (ansl == max(ansl, left + 1)) {
                    ansr = min(ansr, right);
                }
                // ansl 不必改，因提議要求輸出小的
            } else {
                ans = max(ans, (sfx[right] - sfx[left]) * arr[i]);
                ansl = left + 1;
                ansr = right;
            }
        }
        cout << ans << '\n' << ansl << ' ' << ansr << '\n';
    }
}
signed main(void) {
     ac;
    solve();
    return 0;
}