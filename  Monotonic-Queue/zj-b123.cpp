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
void solve(){
    int row,col,arr[205][205]={0},sfx[205][205]={0};
    cin>>row>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                sfx[i][j]=sfx[i-1][j]+1;
        }
    }
    int ans=0;
    
    for(int i=1;i<=row;i++){
        stack<int> st;
        st.push(maxn);
        int width=0,height=0;
        for(int j=1;j<=col;j++){
            
            if(sfx[i][j]==0){
                width=0,height=0;
                while(st.empty())
                    st.pop();
                st.push(maxn);
            }
            if(sfx[i][j]>st.top()){
                
            }
        }
    }
    
}
signed main(void)
{ac;
  solve();
  return 0;
}