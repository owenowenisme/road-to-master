#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false);cin.tie(0)
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
string s;int leng,cnt,flag;
void check(int idx){
    if(s[idx]>=97){
        cnt++;
    }
    if(s[idx]=='N')
        if(cnt<1)flag=1;
    if(s[idx]=='C'||s[idx]=='D'||s[idx]=='E'||s[idx]=='I'){
        if(cnt<=1) 
            flag=1;
        else
            cnt--;
    }

}


void solve(){
    
    while(cin>>s){
        cnt=0;
        flag=0;
        leng=s.length()-1;//last index
        
        for(int i=leng;i>=0;i--){
            check(i);
        }
        //debug(cnt,flag);
        (cnt==1&&flag==0) ?cout<<"YES\n" : cout<<"NO\n";
    }
    
}
signed main(void)
{ac;
  solve();
  return 0;
}