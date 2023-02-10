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
pair<int,int>p[100005],tmp[100005];
int n;
bool cmp(pair<int,int> a,pair<int,int>b){
    return a.second<b.second;
}
int dis(pair<int,int> a,pair<int,int>b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int dc(int l,int r){
    if(l>=r) return 1e11;
    int m=(l+r)/2;
    pair<int,int>a=p[m];

    int ans=min(dc(l,m),dc(m+1,r));
    int j=m+1,k=0;
    
    for(int i=l;i<=m;i++){//merge sort with y
        while(j<=r&&p[j].second<p[i].second){
            tmp[k++]=p[j++];
        }
        tmp[k++]=p[i];
    }
    for(int i=l;i<j;i++){
        p[i]=tmp[i-l];
    }
    k=0;

    for(int i=l;i<=r;i++){//put only between mid.x-ans,mid.x-ans
        if(abs(a.first-p[i].first)<ans){
            tmp[k++]=p[i];
        }
    }
    for(int i=0;i<k;i++){
        for(int o=i+1;o<k&&abs(tmp[o].second-tmp[i].second)<ans;o++)
            ans=min(ans,dis(tmp[i],tmp[o]));
    }
    return ans;
}
void solve(){
    cin>>n;
    rep(i,0,n)
        cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    cout<<dc(0,n-1)<<'\n';
    
}
signed main(void){
    ac;
    solve();
    return 0;
}
