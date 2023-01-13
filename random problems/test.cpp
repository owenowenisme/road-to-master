#include <bits/stdc++.h>
using namespace std;
#define N 100005
struct guild {
    int m, s, t;
};
bool cmp(guild a, guild b) { return a.s < b.s; }
struct cmp2 {
    bool operator()(guild a, guild b) {
        return a.t > b.t;  // 需要反向定義
    }
};
guild g[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mx = 0;
    priority_queue<guild, vector<guild>, cmp2> pq;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> g[i].m >> g[i].s >> g[i].t;
    sort(g, g + n, cmp);
    for (int i = 0, mb; i < n; i++) {  // mb=maxbuffer
        mb = 0;
        priority_queue<guild, vector<guild>, cmp2> buffer;
        mb += g[i].m;
        while (!pq.empty()) {
            guild top;
            top = pq.top();
            if (g[i].s <= top.t) {
                mb += top.m;
            } else {
                break;
            }
            buffer.push(top);
            pq.pop();
        }   
        mx = max(mx, mb);
        pq = buffer;
        pq.push(g[i]);
    }
    cout << mx;
    return 0;
}
