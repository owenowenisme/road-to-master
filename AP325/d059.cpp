#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
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
int n,d,arr[100005]={0};
int f(int num){
    priority_queue<int,vector<int>,greater<int>>pq;
    rep(i,0,num){
        pq.push(0);
    }
    int tmp;
    rep(i,0,n){
        tmp=pq.top()+arr[i];
        pq.pop();
        pq.push(tmp);
        if(tmp>d)
            return 1;
    }
    return 0;
}
void solve() {
    cin >> n >> d;
    rep(i, 0, n) cin >> arr[i];

    int l = 1, r = n, mid = (l + r) / 2;
    while (l < r) {
        mid = (l + r) / 2;
        if (f(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << r;
}
signed main(void){
    ac;
    solve();
    return 0;
}