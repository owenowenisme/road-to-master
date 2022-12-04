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
int func(){
    string s;
    cin>>s;
    int x,y,z;
    if(s[0]=='f'){
        x=func();
        return 2*x-3;
    }
    if(s[0]=='g'){
        x=func();
        y=func();
        return 2*x+y-7;
    }
    if(s[0]=='h'){
        x=func();
        y=func();
        z=func();
        return 3*x-2*y+z;
    }
    return stoi(s);

}
void solve(){
    cout<<func();
}
signed main(void)
{ac;
  solve();
  return 0;
}