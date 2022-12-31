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
    int t;cin>>t;
    
    while(t--){
        int tmp;
        int arr[2000]={0};
        int n,m;
        cin>>n>>m;
        int idx=0;
        for(;idx<n;idx++)
        cin>>arr[idx];
        for(;idx<m+n;idx++)
        cin>>arr[idx];
        tmp=arr[m+n-1];
        sort(arr,arr+m+n,greater<int>());
        int ans=0;
        for(int i=0;i<n;i++)
        ans+=arr[i];
        if(n==1)ans=tmp;
        cout<<ans<<'\n';
    }

}
signed main(void)
{ac;
  solve();
  return 0;
}