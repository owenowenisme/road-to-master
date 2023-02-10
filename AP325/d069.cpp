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
int m,n,arr[205][205]={0};
void solve(){
    rep(i,2,205)
        arr[0][i]=-1000000000;
    rep(i,2,205)
        arr[i][0]=-1000000000;
    cin>>m>>n;
    rep(i,1,m+1){
        rep(j,1,n+1){
            cin>>arr[i][j];
            arr[i][j]=max(arr[i-1][j],arr[i][j-1])+arr[i][j];
        }
    }
    cout<<arr[m][n];
}
signed main(void){
    ac;
    solve();
    return 0;
}