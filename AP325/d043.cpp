#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
//#define int long long
#define F first
#define S second
const int maxn=1e5+5;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int a[maxn]={0};
void solve(){
    int tmp,n;cin>>n;

    priority_queue<int,vector<int>> pq;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>tmp;
        pq.push(tmp);
    }
    sort(a,a+n,greater<int>());
    int ans=0;
    cout<<'\n';
    for(int i=0;i<n;i++){
        if(a[i]<pq.top()){
            pq.pop();
            ans++;
        }
    }
    cout<<ans;
}
signed main(void)
{ac;
  solve();
  return 0;
}