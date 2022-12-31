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
int n;int h[200005]={0},p[200005]={0};
map<int,int>mp;int ans=0;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<=n;i++){
        cin>>p[i];
        p[i]+=h[i];
    }
    mp.insert({10000000000,0});
    for(int i=1;i<=n;i++){
        auto it=mp.begin();
        while(it->first<=h[i])
            mp.erase(it++);
        auto a=mp.upper_bound(p[i]);
        ans+=i-a->second-1;
        mp.insert({h[i],i});
    }
    cout<<ans;
}
signed main(void)
{ac;
  solve();
  return 0;
}    