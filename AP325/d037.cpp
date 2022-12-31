#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
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
 vector<pair<int,int>>v;
 deque<int>maxdq,mindq;
 int arr[200005]={0};
 int tmp;
void dqmax(int i) {
    if (!maxdq.empty()){
        while (v[maxdq.back()].second < v[i].second) {
            maxdq.pop_back();
            if (maxdq.empty()) break;
        }
    }
    maxdq.push_back(i);
    return;
}
void dqmin(int i) {
   
    if (!mindq.empty()){
        while (v[mindq.back()].second > v[i].second) {
            mindq.pop_back();
            if (mindq.empty()) break;
        }
    }
    mindq.push_back(i);
    return;
}
void solve(){
    int ans=0;
    int n,l;
    cin>>n>>l;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    v.pb({-1e12,-1e12});
    for(int i=1;i<=n;i++){
        cin>>tmp;
        v.pb({arr[i],tmp});
    }
    sort(v.begin(),v.end());
    

    maxdq.push_back(1);
    mindq.push_back(1);
    int head=1,tail=0;
    for(int i=2;i<=n;i++){
        while(!maxdq.empty()&&v[i].first-v[maxdq.front()].first>l)
            maxdq.pop_front();
        while(!mindq.empty()&&v[i].first-v[mindq.front()].first>l)
            mindq.pop_front();
        
        dqmax(i);
        dqmin(i);
        ans=max({abs(v[i].second-v[mindq.front()].second),abs(v[i].second-v[maxdq.front()].second),ans});
    }  
    cout<<ans<<'\n';
}
signed main(void)
{ac;
  solve();
  return 0;
}