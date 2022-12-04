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
    deque <int> dq;
    int arr[100005]={0},sfx[100005]={0};
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sfx[i]=sfx[i-1]+arr[i];
    }
    int ans=0;
    // for(int i=1;i<=n;i++){
    //     cout<<sfx[i]<<' ';
    // }
    int idx[100005]={0};
    int head=0,tail=0;
    for(int i=1;i<=n;i++){
        if(idx[head]<i-k){
            head++;
        }
        ans=max(ans,sfx[i]-arr[head]);
        while(head<=tail&&arr[tail]>=sfx[i]){
            tail--;
        }
        tail++;
        arr[tail]=sfx[i];
        idx[tail]=i;
    }
    cout<<ans<<'\n';
     
}
signed main(void)
{ac;
  solve();
  return 0;
}