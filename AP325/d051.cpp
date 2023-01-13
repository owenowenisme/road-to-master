#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
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
    int minn=1e9,maxx=0,ans=0,tmp=0;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp<minn){
            minn=tmp;
            maxx=tmp;
        }
        else{
            maxx=max(tmp,maxx);
        }
        ans=max(maxx-minn,ans);
    }
    cout<<ans;
}
signed main(void)
{ac;
  solve();
  return 0;
}