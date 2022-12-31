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
unordered_map<int,int>mp;
int n, l, arr[200005] = {0};
    long unsigned ans = 0;
    void solve() {
        cin >> n >> l;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int head = 0, tail = l;
        for (int i = 1; i <= tail; i++) mp[arr[i]]++;
        ans = mp.size();

        while (tail < n) {
            tail++;
            head++;
            mp[arr[tail]]++;
            if (mp[arr[head]] == 1)
                mp.erase(arr[head]);
            else
                mp[arr[head]]--;
            ans = max(mp.size(), ans);
        }
        cout << ans;
    }
    signed main(void) {
        ac;
        solve();
        return 0;
    }