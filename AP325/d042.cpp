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
void solve(){
 int t,n;cin>>t;int ans=0;
 while(t--&&cin>>n){
    ans=0;
    ans+=n/50;
    n%=50;
    ans+=n/10;
    n%=10;
    ans+=n/5;
    ans+=n%=5;
    cout<<ans<<'\n';
 }
}
signed main(void)
{ac;
  solve();
  return 0;
}