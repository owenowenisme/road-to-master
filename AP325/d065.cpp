#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
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
int n,arr[100005];
int sub(int l,int r){
    if(l>=r)return 0;
    if(r-l==1)return arr[l];
    int m=(l+r)/2;
    int ans=max(sub(l,m),sub(m+1,r));
    int tmp=0,h=arr[m],i=m,j=m;
    while(i>=l||j<r){
        if (i < l)
            h = arr[j];
        else if (j >= r)
            h = arr[i];
        else
            h = max(arr[i], arr[j]);
        while (i >= l && h <= arr[i]) i--;
        while (j < r && h <= arr[j]) j++;
        tmp = max(tmp, (j - i - 1) * h);
    }
    return max(ans,tmp);
}
void solve(){
    cin>>n;
    rep(i,0,n)
        cin>>arr[i];
    cout<<sub(0,n);
}
signed main(void){
    ac;
    solve();
    return 0;
}