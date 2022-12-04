#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define int long long
#define F first
#define S second
#define maxn 1e8
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
string s;
int idx=-1,n,leng;
int recu(int edge){
    idx++;
   
    if(idx==leng||s[idx]=='0')
        return 0;
    if(s[idx]=='1')
        return edge*edge;
    
    int cnt=0;
    for(int i=0;i<4;i++)
        cnt+=recu(edge/2);

    return cnt;
}
void solve(){
    cin>>s>>n;
    leng=s.length();
    cout<<recu(n);
}
signed main(void)
{ac;

  solve();
  return 0;
}