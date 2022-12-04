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
    cout<<'\n';
    dq.push_back(sfx[1]);
    int head=1,tail=1;
    int index[100005]={0};
    index[1]=1;
    for(int i=2;i<=n;i++){
        while(!dq.empty()&&index[head]<i-k){
            
            head++;
            dq.pop_front();
        }
        ans=max(ans,sfx[i]-dq.front());
        while(!dq.empty()&&dq.back()>=sfx[i]){
            dq.pop_back();
            tail--;
        }
        tail++;
        dq.push_back(sfx[i]);
        index[tail]=i;
        
    }
    
        
    ans=max(ans,sfx[n]-dq.front());
    cout<<ans<<'\n';
     
}
signed main(void)
{ac;
  solve();
  return 0;
}