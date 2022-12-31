#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define pb push_back
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
void debug_out() { cerr << "]\n"<< flush; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){cerr << H;if (sizeof...(T))cerr << ", ";debug_out(T...);}
#define debug(...) cerr << "LINE(" << __LINE__ << ") : [" << #__VA_ARGS__ << "] = ["; debug_out(__VA_ARGS__)
int arr[200005]={0};
int n,l;
int ans=0;
deque<int>maxdq,mindq;
void dqmax(int i) {
    if (maxdq.empty())
        maxdq.push_back(i);
    else {
        while (arr[maxdq.back()] < arr[i]) {
            maxdq.pop_back();
            if (maxdq.empty()) break;
        }
        maxdq.push_back(i);
    }
    return;
}
void dqmin(int i) {
    if (mindq.empty())
        mindq.push_back(i);
    else {
        while (arr[mindq.back()] > arr[i]) {
            mindq.pop_back();
            if (mindq.empty()) break;
        }
        mindq.push_back(i);
    }
    return;
}
void solve() {
    cin >> n >> l;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int head = 1, tail = l;
    for (int i = 1; i <= l; i++) {
            dqmax(i);
            dqmin(i);
    }
    ans = arr[maxdq.front()] - arr[mindq.front()];
    while (tail < n) {
            head++;
            tail++;
            if (maxdq.front() < head) maxdq.pop_front();
            if (mindq.front() < head) mindq.pop_front();
            dqmax(tail);
            dqmin(tail);
            ans = max(ans, arr[maxdq.front()] - arr[mindq.front()]);
    }
    cout << ans;
}
signed main(void) {
    ac;
    solve();
    return 0;
}