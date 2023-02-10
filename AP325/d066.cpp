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
void solve(){
    int n,arr[100005]={0};
    cin>>n>>arr[0]>>arr[1];
    rep(i,2,n){
        cin>>arr[i];
        arr[i]=min(arr[i-1],arr[i-2])+arr[i];
    }
    cout<<arr[n-1];
}
signed main(void){
    ac;
    solve();
    return 0;
}