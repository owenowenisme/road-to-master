#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
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
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
void solve(){
    int m,n,k,tmp;
    int a[100005],b[100005];
    while(cin>>m>>n>>k){
        int ans=0;
        
        for(int i=0;i<m;i++)
            cin>>a[i];
        
        for(int i=0;i<n;i++)
            cin>>b[i];
        
        sort(a,a+m);sort(b,b+n);
        int i=0,j=n-1;
        while(i<m&&j>=0){
            tmp=a[i]+b[j];
            if(tmp==k){
                ans++;
                i++;j--;
            }
            else if(tmp<k)i++;
            else if(tmp>k)j--;
        }
        cout<<ans<<'\n';
    }
}
signed main(void)
{ac;
  solve();
  return 0;
}