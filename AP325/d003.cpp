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
int arr[50005]={0};
int n,leng,tmp;

int cut(int begin, int end) {
    if (end - begin <= 1) return 0;
    int l = begin, r = end, m = (l + r) / 2;

    double val = ((double)arr[begin] + (double)arr[end]) / 2;
    int v = (arr[begin] + (double)arr[end]) / 2;
    
    while (l < r) {
        m = (l + r) / 2;
        if (arr[m] <= v)
            l = m + 1;
        else
            r = m;
    }

    m = l;
    // m=lower_bound(arr+begin,arr+end,v)-arr;implement with lowerbound
    if (val - arr[m - 1] <= arr[m] - val) m--;
    return arr[end] - arr[begin] + cut(begin, m) + cut(m, end);
}
void solve() {
    cin >> n >> leng;
    arr[0] = 0;
    arr[n + 1] = leng;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << cut(0, n + 1);
}
signed main(void) {
    ac;
    solve();
    return 0;
}