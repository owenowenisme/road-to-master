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
pair<int,int>p[100005];
pair<int,int> s;
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    s=p[0];
    int ans=0;
    for(int i=1;i<n;i++){
        if(p[i].first<=s.second)
            s.second=max(s.second,p[i].second);
        else{
            ans+=s.second-s.first;
            s=p[i];
        }
    }
    ans+=s.second-s.first;
    cout<<ans;
}
signed main(void)
{ac;
  solve();
  return 0;
}