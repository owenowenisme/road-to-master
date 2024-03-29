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
struct mydata{
    int id;
    int age;
    int gender;
    int salary;

};
typedef mydata mydata;
bool cmp(mydata a,mydata b){
    if(a.salary!=b.salary)
        return a.salary<b.salary;
    else{
        if(a.age!=b.age)
            return a.age<b.age;
        else{
            if(a.gender==b.gender)
                return a.id<b.id;
            return a.gender<b.gender;
        }
    }

}
void solve(string filename){
    fstream file;
    file.open(filename);
    mydata m[100000];
    string tmp;
    stringstream ss;
    int idx=0;int arr[4];
    while(getline(file,tmp)){
        ss<<tmp;
        int id=0;
        while(getline(ss,tmp,',')){
            if(id!=2)
                arr[id]=stoi(tmp);
            else
                arr[id]=tmp[0];
            id++;
        }
        m[idx].id=arr[0];
        m[idx].age=arr[1];
        m[idx].gender=arr[2];
        m[idx].salary=arr[3];
        idx++;
        ss.clear();
    }
    sort(m,m+idx,cmp);

    int now_salary=-1;
    for(int i=0;i<idx;i++){

        if(m[i].salary!=now_salary){
            cout<<m[i].salary;
            now_salary=m[i].salary;
        }
        cout<<','<<m[i].id;
        if(i!=idx-1&&now_salary!=m[i+1].salary)
            cout<<'\n';

    }
}
signed main(int argc,char *argv[]){ac;
    solve(argv[1]);
    return 0;
}