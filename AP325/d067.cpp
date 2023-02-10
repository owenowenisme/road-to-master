#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
#define pb push_back
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
int n,arr[100005]={0};
void solve(){
    cin>>n>>arr[1]>>arr[2];
    rep(i,3,n+1){
        cin>>arr[i];
        arr[i]=max(arr[i-2],arr[i-3])+arr[i];
    }
    cout<<max(arr[n],arr[n-1]);
}
signed main(void){
    ac;
    solve();
    return 0;
}