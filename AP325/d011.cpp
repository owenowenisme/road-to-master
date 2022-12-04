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
    map<int,int> mp;
    set<int>st;
    int n,tmp;cin>>n;
    int arr[100005];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }
    int idx=0;
    for(auto a:st)
        mp[a]=idx++;
    
    for(int i=0;i<n;i++)
        cout<<mp[arr[i]]<<' ';
}
signed main(void)
{ac;
  solve();
  return 0;
}