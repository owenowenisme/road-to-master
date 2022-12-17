#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
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
    string s;
    map<char, char> bra = {{']', '['}, {'}', '{'}, {')', '('}};
    while (cin >> s) {
        stack<char> st;
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (st.empty())
                st.push(s[i]);
            else
                (bra[s[i]] == st.top()) ? st.pop() : st.push(s[i]);
        }
        (st.empty()) ? cout << "yes\n" : cout << "no\n";
    }
}
signed main(void) {
    ac;
    solve();
    return 0;
}