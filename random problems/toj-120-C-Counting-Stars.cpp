#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false);cin.tie(0);
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first
#define S second
#define maxn 1e8
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; \debug_out(__VA_ARGS__)
void solve(){
    
    int n;int star[200005]={0};
    int suffix[200005]={0}; 
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>star[i];
        suffix[i]=star[i]+suffix[i-1];
    }
    int t;cin>>t;int a,b;

    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(a>b)swap(a,b);
        cout<<suffix[b]-suffix[a]+star[a]<<'\n';
    }
}
signed main(void)
{ac
  solve();
  return 0;
}