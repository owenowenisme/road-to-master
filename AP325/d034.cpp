#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int arr[200005]={0};
unordered_map<int,int> refer,mp;
unordered_set<int>st;
void solve() {
    int n;
    cin >> n;
    int ans = 1e+10;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        st.insert(arr[i]);
    }

    int tail, head = 1;
    int color = st.size();

    for (int i = 1; i <= n; i++) {
        mp[arr[i]]++;
        if (mp.size() == color) {
            tail = i;
            break;
        }
    }

    while (mp[arr[head]] > 1) {
        mp[arr[head]]--;
        head++;
    }

    ans = min(ans, tail - head + 1);

    while (tail < n) {
        tail++;
        mp[arr[tail]]++;
        while (mp[arr[head]] > 1) {
            mp[arr[head]]--;
            head++;
        }
        ans = min(ans, tail - head + 1);
    }
    cout << ans;
}

signed main(void)
{ac;
  solve();
  return 0;
}