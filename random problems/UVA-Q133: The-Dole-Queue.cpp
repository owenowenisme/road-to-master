#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false);cin.tie(0);
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

signed main(void)
{
    int n, k, m;
    while (cin >> n >> k >> m && n != 0)
    {
        
        int arr[25];
        mem(arr, 0);
        int pick1, pick2;
        int count = n;
        int nowa = 0, nowb = n - 1;
        while (count > 0)
        {

            int kk = k, mm = m;
            while (kk > 0)
            {
                if (arr[nowa] == 0)
                {
                    kk--;
                }
                if (kk != 0)
                    nowa++;
                nowa %= n;
            }

            while (mm > 0)
            {
                if (arr[nowb] == 0)
                {
                    mm--;
                }
                if (mm != 0)
                    nowb--;

                while (nowb < 0)
                    nowb += n;
            }
            if (count > 1&&!(count==2&&nowa!=nowb))
            {
                if (nowa == nowb)
                    cout << setw(3) << nowa + 1 << ',';
                else
                {
                    cout << setw(3) << nowa + 1;
                    cout << setw(3) << nowb + 1 << ',';
                }
            }

            arr[nowa] = 1;
            arr[nowb] = 1;
            if (nowa != nowb){
                count--;
            }
                
            count--;
        }
        if (nowa == nowb)
                    cout << setw(3) << nowa + 1 ;
                else 
                {
                    cout << setw(3) << nowa + 1;
                    cout << setw(3) << nowb + 1 ;
                }
            cout<<'\n';
    }
}