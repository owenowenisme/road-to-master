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
int ps[100005]={0};
void solve(){
    set<int>st;
    int n,k;
    cin>>n>>k;
    ps[0]=0;int tmp;int ans=0;
    st.clear();
    st.insert(0);
    for(int i=1;i<=n;i++){
        cin>>tmp;
        ps[i]=tmp+ps[i-1];
        auto s=(st.lower_bound(ps[i]-k));
        ans=max(ans,ps[i]-(*s));
        st.insert(ps[i]);
    }
    cout<<ans;
}
signed main(void)
{ac;
  solve();
  return 0;
}