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
string s;int p;
int fastpow(int x, int y, int a) {
    int ans = 1;
    if (y >= 1) {
        int tmp = fastpow(x, y>>1, a) % a;
        if (y % 2)
            ans = (((tmp * tmp) % a) * x) % a;
        else
            ans = (tmp * tmp) % a;
    }
    return ans;
}
int divide(string s,int t ){
    int leng=s.length(),tmp=0;
    for(int i=0;i<leng;i++){
        tmp=((tmp*10)+s[i]-48)%t;
    }
    return tmp;
}
void solve() {
    int x, y, a;
    cin >> s >> y >> a;
    x=divide(s,a);
    cout << fastpow(x, y, a);
}
signed main(void) {
    ac;
    solve();
    return 0;
}