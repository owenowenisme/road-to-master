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
string s;int p[4];
struct mat {
    int p[4] = {1, 1, 1, 0};
};
mat init;
mat matrix(mat a, mat b, int q) {
    mat tmp;
    tmp.p[0] = ((a.p[0] * b.p[0]) % q + (a.p[1] * b.p[2]) % q) % q;
    tmp.p[1] = ((a.p[0] * b.p[1]) % q + (a.p[1] * b.p[3]) % q) % q;
    tmp.p[2] = ((a.p[2] * b.p[0]) % q + (a.p[3] * b.p[2]) % q) % q;
    tmp.p[3] = ((a.p[2] * b.p[1]) % q + (a.p[3] * b.p[3]) % q) % q;

    return tmp;
}
mat fastpow(int y, int a) {
    mat ans;
    ans.p[0] = 1;
    ans.p[1] = 0;
    ans.p[2] = 0;
    ans.p[3] = 1;
    if (y >= 1) {
        mat tmp = fastpow(y >> 1, a);
        if (y % 2)
            ans = (matrix((matrix(tmp, tmp, a)), init, a));
        else
            ans = (matrix(tmp, tmp, a));
    }
    return ans;
}

void solve() {
    int x;
    while (cin >> x && x != -1) 
        cout << fastpow(x - 1, 1000000007).p[0] << '\n';
}
signed main(void) {
    ac;
    solve();
    return 0;
}