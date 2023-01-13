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

typedef struct party{
    int num=0;
    int arr=0;
    int lve=0;
} party;
party p[100005];
int cmp(party &a,party &b){
    return a.arr<b.arr;
}
struct cmp2{
bool operator()(party &a,party &b){
    return a.lve>b.lve;
}
};
void solve(){
    int n;cin>>n;
    rep(i,0,n)
        cin>>p[i].num>>p[i].arr>>p[i].lve;
    sort(p,p+n,cmp);
    int ans=0,pqsum=0;
    priority_queue<party,vector<party>,cmp2>pq;
    rep(i,0,n){
        while(!pq.empty()){
            if(p[i].arr>pq.top().lve){
                pqsum-=pq.top().num;
                pq.pop();
            }
            else break;
        }
        pqsum+=p[i].num;
        pq.push(p[i]);
        ans=max(pqsum,ans);
    }
    cout<<ans;
}
signed main(void){
    ac;
    solve();
    return 0;
}