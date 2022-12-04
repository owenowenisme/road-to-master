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

void solve() {
   int arr[30][30]={0},sfx[30][30]={0};
   
   char c;int col=1,row=1;
   
   while((c=getchar())!=EOF){
        
        if(c=='\n'){
            row++;
            col=1;
        }
        else{
            arr[row][col]=c-48;
            sfx[row][col]=sfx[row-1][col]+arr[row][col];
            col++;
        }
   }
   


}
signed main(void) {

    ac;
    solve();
    
    return 0;
}