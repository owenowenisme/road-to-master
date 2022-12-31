#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
//#define int long long
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int n, m, arr[200005]={0};
unordered_map<int,int>mp;
void solve(){
    cin>>m>>n;int ans=0;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int head=1,tail=m;
    for(int i=1;i<=tail;i++){
        mp[arr[i]]++;
    }
    int cur=mp.size();
    if(cur==m)ans++;
    while(tail<n){
        tail++;
        
        mp[arr[tail]]++;
        if(mp[arr[head]]<=1)mp.erase(arr[head]);
        else mp[arr[head]]--;
        head++;
        cur=mp.size();
        if(cur==m)ans++;
    }
    cout<<ans;

}
signed main(void)
{ac;
  solve();
  return 0;
}