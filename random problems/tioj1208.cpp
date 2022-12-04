#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first
#define S second
#define maxn 1e+14;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int pfx[200005];
int PFX[200005];
int tmp[200005];
int n,k;
//int cnt;
int mergesort(int l, int r, int q) {
   // debug(l, r, q);
    if (l >= r) {
        //debug("end");
        return 0;
    }

    int cnt = 0;
    int m = (l + r) / 2;

    cnt += mergesort(l, m, q);
    cnt += mergesort(m + 1, r, q);

    for (int i = l; i <= m; i++) {
        int t = upper_bound(PFX + m + 1, PFX + r+1, PFX[i] + q) - PFX;
        //debug(q,r - t + 1,PFX[i]+q);
        cnt +=  r -t+ 1;
    }

    int i = l, idx = l, j = m + 1;
    
    while (i <= m && j <= r) {
        if (PFX[i] > PFX[j])
            tmp[idx++] = PFX[j++];
        else
            tmp[idx++] = PFX[i++];
    }
    while (i <= m) tmp[idx++] = PFX[i++];
    while (j <= r) tmp[idx++] = PFX[j++];

    memcpy(PFX + l, tmp + l, sizeof(int) * (r - l + 1));
    return cnt;
}

bool cmp(int q){
    memcpy(PFX,pfx,sizeof(pfx));
    if (mergesort(0,n,q)+1>k)
    return 1;
        return 0;   
}


void solve(){
    int tmp;
    while(cin>>n>>k&&!(n==0&&k==0)){
        pfx[0]=0;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            pfx[i]=pfx[i-1]+tmp;
        }
        memcpy(PFX,pfx,sizeof(pfx));
        
    
        int lb=-200000005,ub=200000005,mid;
            
        // int lb = n * (-10000) - 1;
        // int ub = n * (+10000);
        while (lb<ub) {
            //debug(lb,mid,ub);
             mid = (lb + ub) / 2;
            if (cmp(mid)) lb = mid;
            else ub = mid-1;
            
        }
        //debug(lb,mid,ub);
        printf("%d\n", ub+1);
}
}
signed main(void)
{ac;
  solve();
  return 0;
}