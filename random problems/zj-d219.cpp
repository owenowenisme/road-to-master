#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false);cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int  long long
#define F first
#define S second
#define maxn 1e8
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; \debug_out(__VA_ARGS__)
int b,p,m;
int fastpow(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1)
        return a%m;
    if(b%2==0){
        int tmp= fastpow(a,b/2)%m;
        return (tmp*tmp)%m;
    }
    else{
        int tmp=fastpow(a,b/2)%m;
        return (tmp*tmp*a)%m;
    }
         
    
}
void solve(){
    
        while(cin>>b>>p>>m){
        cout<<fastpow(b,p)%m<<'\n';
        }
    
}
signed main()
{
  solve();
  return 0;
}