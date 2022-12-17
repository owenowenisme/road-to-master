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
    cin >> s;
    int l = s.length();
    stack<int> ant;//operatant
    stack<char> tor;//operator
    ant.push(s[0] - '0');
    for (int i = 1; i < l; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (tor.top() == '-') {
                int tmp = -(s[i] - '0');
                tor.pop();
                tor.push('+');
                ant.push(tmp);
            } else if (tor.top() == '*') {
                tor.pop();
                int tmp = ant.top();
                ant.pop();
                ant.push(tmp * (s[i] - '0'));
            } else if (tor.top() == '/') {
                tor.pop();
                int tmp = ant.top();
                ant.pop();
                ant.push(tmp / (s[i] - '0'));
            } else
                ant.push(s[i] - '0');
        } 
        else {
            tor.push(s[i]);
        }
    }

    while (!tor.empty()) {
        if (tor.top() == '+') {
            tor.pop();
            int tmp = ant.top();
            ant.pop();
            tmp += ant.top();
            ant.pop();
            ant.push(tmp);
        }
    }

    cout << ant.top();
}
signed main(void) {
    ac;
    solve();
    return 0;
}