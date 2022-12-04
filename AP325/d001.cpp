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

int func() {
    int x,y;
    string s;
    cin >> s;
    if (s[0] == 'f') {
        x = func();
        return x * 2 - 1;
    } 
    else if (s[0] == 'g') {
        x = func();
        y = func();
        return x + 2 * y - 3;
    }
        return stoi(s);
}
void solve() { cout << func(); }
signed main(void) {
    ac;
    solve();
    return 0;
}