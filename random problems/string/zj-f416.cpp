#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
#define pb push_back
#define int unsigned int
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
int nextt[1000005]={0};
void solve(){
    int n;cin>>n;
    string s,q;
        cin>>s>>q;
        int sp=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[sp]){
                nextt[i]=nextt[i-1]+1;
                sp++;
            }else{
                nextt[i]=0;
                sp=0;
            }
        }
        sp=0;int times=0;
        for(int i=0;i<q.length();){
            if(q[i]==s[sp]){
                if(sp==s.length()-1){
                    times++;
                    i++;
                    sp=nextt[sp];
                }else{
                    i++;
                    sp++;
                }
            }else{
                if(sp==0)
                    i++;
                else{
                    sp=nextt[sp-1];
                }
            }
        }
        (times==n)?cout<<"YES":cout<<"NO";
}
signed main(void){
    ac;
    solve();
    return 0;
}