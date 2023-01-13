#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
#define pb push_back
//#define int long long
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
pair<int,int>p[100005];
void solve(){
    int n,x,y;cin>>n>>x>>y;
    rep(i,0,n)
        cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    int ans=0;
    stack<pair<int,int>>st;pair<int,int>tmp;
    rep(i,0,n){
        if(p[i].second>=x&&p[i].first<=y){
            if(!st.empty()&&p[i].first>st.top().second){
                cout<<-1;
                return;
            }
            if(!st.empty()&&p[i].second<=st.top().second)
                continue;
            while(!st.empty()&&abs(x-st.top().first)>=abs(x-p[i].first))
                st.pop();
            while(!st.empty()){
                tmp=st.top();
                st.pop();
                if(st.empty()||st.top().second<p[i].first){
                    st.push(tmp);
                    break;
                }
            }
            st.push(p[i]);
            if(st.top().second>=y)
                break;
        }
    }
    ans=st.size();
    cout<<ans;
}
signed main(void){
    ac;
    solve();
    return 0;
}