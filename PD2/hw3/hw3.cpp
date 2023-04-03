#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i=a; i<b; ++i) 
#define pb push_back
#define int long long
#define F first
#define S second
const int maxn=1e8;
const double EPS = 1e-7;
using namespace std;
struct info{
    int id;
    int date=0;
    int time;
    int sign;
};
bool cmp(info a,info b){
    if(a.id==b.id){
        if(a.time==b.time){
            return a.sign<b.sign;
        }
        return a.time<b.time;
    }
    return a.id<b.id;
}
typedef info info;
void solve(char* filename){
    info data[200005];
    freopen(filename,"r",stdin);
    string s;
    stringstream ss;
    int idx=0;
    while(getline(cin,s)){
        ss<<s;int arr[3],id=0;
        while(getline(ss,s,',')){
            if(id==1){
                if(s=="sign-in")
                    arr[1]=0;
                else 
                    arr[1]=1;
            }else{
                arr[id]=stoll(s);
            }
            id++;
        }
        data[idx].id=arr[0];
        data[idx].sign=arr[1];
        data[idx].time=arr[2];
        arr[2]/=10000;
        data[idx].date=arr[2]%10000;
        idx++;
        ss.clear();
    }
    
    sort(data,data+idx,cmp);
    int current_id=data[0].id,current_overload=0,current_forget=0;
    for(int i=1;i<idx;i++){
        if((data[i].date!=data[i-1].date)){
            if(data[i].sign!=-1)
                current_forget++;
        }else{
            data[i].sign=-1;data[i-1].sign=-1;
            if(data[i].time-data[i-1].time>800)
                current_overload++;
        }
        if(current_id!=data[i].id){
            cout<<current_id<<','<<current_overload<<','<<current_forget<<'\n';
            current_overload=0;
            current_forget=0;
            current_id=data[i].id;
        }
        
    }
    cout<<current_id<<','<<current_overload<<','<<current_forget;
}
signed main(int argc,char *argv[]){//ac;
    solve(argv[1]);
    return 0;
}