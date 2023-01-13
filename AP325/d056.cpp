#include <bits/stdc++.h>ㄘㄧㄛㄘㄧㄛ
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define x first
#define y second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)

pair<int,int>p[100005];
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;
    
    sort(p,p+n);
    
    int ans=5e11;
    map<int,int>mp;

    for (int i = 0; i < n; i++) {
        auto it = mp.lower_bound(p[i].y - ans);
        while (it != mp.end() && it->first <= ans + p[i].y) {
            if (it->second < (p[i].x - ans)) {
                it = mp.erase(it);
                continue;
            }
            ans = min(ans,abs(p[i].x - it->second) + abs(p[i].y - it->first));
            it++;
        }
        mp.insert({p[i].y, p[i].x});
    }
    cout<<ans;
}
signed main(void)
{ac;
  solve();
  return 0;
}