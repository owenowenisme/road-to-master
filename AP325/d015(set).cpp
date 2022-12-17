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
    unordered_set<int>a,b;
    int m,n,k,tmp;
    while(cin>>m>>n>>k){
        int ans=0;
        a.clear();b.clear();
        
        for(int i=0;i<m;i++){
            cin>>tmp;
            a.insert(tmp);
        }
        for(int i=0;i<n;i++){
            cin>>tmp;
            b.insert(tmp);
        }
        for(auto q:a){
            tmp=k-q;
            if(b.find(tmp)!=b.end())
                ans++;
        }
        cout<<ans<<'\n';
    }
}
signed main(void)
{ac;
  solve();
  return 0;
}