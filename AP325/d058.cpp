

#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first

#define S second
const int maxn=1e8;
const double EPS = 1e-7;
#define  rep(i, a, b) for (int i=a; i<b; ++i) 
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
void solve(){
    int n;cin>>n;
    pair<int,int>p[100005];
    rep(i,1,n+1)
        cin>>p[i].second;
    rep(i,1,n+1)
        cin>>p[i].first;
    sort(p,p+n+1);
    rep(i,1,n+1){
        p[i].second+=p[i-1].second;
        if(p[i].second>p[i].first){
            cout<<"no\n";
            return;
        }
    }
    cout<<"yes\n";
}
signed main(void){ac;
    int t;cin>>t;
    for(int i=0;i<t;i++)
        solve();
    return 0;
}