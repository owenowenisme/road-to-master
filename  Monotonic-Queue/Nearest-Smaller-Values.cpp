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
stack <pair<int,int>> st;
void solve(){
    int n;int smallest =1e+10;
    cin>>n;
    st.push({0,0});
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        while(st.top().second>tmp){
            st.pop();
        }
        smallest=min(smallest,tmp);
        
        if(smallest==tmp) 
            cout<<"0 ";
        else
            cout<<st.top().first<<' ';
        
        st.push({i,tmp});
    }
    
 
}
signed main(void)
{ac;
  solve();
  return 0;
}