#include <iostream>
#include <queue>
using namespace std;

int n, limit, cnt;
int x[15], k = 1;
//行，左對角線，右對角線
void DFS(int row,int left,int right) {
    if (row != limit) {
        int pos = limit & ~(row | left | right);
        while (pos) {
            //找到的可以放皇后的位置
            int p = pos & -pos;// pos & (~pos+1);
            pos &= pos - 1;
            if (cnt < 3) {
                int t = p, num = 1;
                while (t != 1) {
                    num++;
                    t >>= 1;
                }
                x[k++] = num;
            }
            DFS(row | p, (left | p) << 1, (right | p) >> 1);
            if (cnt < 3) k--;
        }
    }
    else {
        cnt++;
    }
}

int main() {
    while(cin>>n){
        cnt=0,k=1;
    limit = (1 << n) - 1;
    DFS(0, 0, 0);
    cout << cnt << endl;
}
return 0;
}