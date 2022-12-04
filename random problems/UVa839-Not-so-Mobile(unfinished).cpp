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
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; \debug_out(__VA_ARGS__)

struct libra{
    int lw,ll,rw,rl;
}mobile,tmp;
int cmp(int lw,int ll,int rw,int rl){
    if(lw*ll==rw*rl)
        return 1;
    return 0;
}
stack<libra> st;

void solve(){
    int t; cin>>t;
    for(int i=0;i<t;i++){
        int flag=1;
        while(!st.empty())
            st.pop();
        //cout<<"hereee"<<i<<' '<<flag<<"\n";
        while(cin>>mobile.lw>>mobile.ll>>mobile.rw>>mobile.rl){
            //printf("%d %d %d %d ",mobile.lw,mobile.ll,mobile.rw,mobile.rl);
            //cout<<"here"<<i<<' '<<flag<<"\n";
            if(!st.empty())
            if(cmp(mobile.lw,mobile.ll,mobile.rw,mobile.rl)==0){
                flag=0;
                //cout<<"checkmateccccccc";
                break;
            }
            st.push(mobile);
            while(st.top().lw!=0&&st.top().rw!=0&&st.size()!=1){
                tmp=st.top();
                st.pop();
                if(st.top().lw==0)
                    st.top().lw=tmp.lw+tmp.rw;
                else 
                    st.top().rw=tmp.lw+tmp.rw;
                if(st.top().lw!=0&&st.top().rw!=0&&cmp(st.top().lw,st.top().ll,st.top().rw,st.top().rl)==0){
                    flag=0;
                    //cout<<"checkmatefmvijnfv";
                    break;
                }
                //printf("result%d %d %d %d here\n",st.top().lw,st.top().ll,st.top().rw,st.top().rl);
            }
            if(flag==0)break;
            if(st.size()==1&&st.top().lw!=0&&st.top().rw!=0){
            if(!st.empty()&&cmp(st.top().lw,st.top().ll,st.top().rw,st.top().rl)==0){
                flag=0; 
                //cout<<"checkmate";
            break;
            }
                
            }
        }   
        (flag)? cout<<"YES\n\n":cout<<"NO\n\n";
    
}
}
signed main(void)
{
  solve();
  return 0;
}