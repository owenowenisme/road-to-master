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
typedef pair<int,int> pii;

vector<pii>v;
void solve(){
    int n;cin>>n;
    int a,b;
    int ans=0,end=-1;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.pb({b,a});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(v[i].second>end){
            ans++;
            end=v[i].first;
        }
    }
    cout<<ans;
}
signed main(void)
{ac;
  solve();
  return 0;
}