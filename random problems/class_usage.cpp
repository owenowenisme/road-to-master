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
class Whatever{
    public:
        int var1=123;
        int var2=456;
        Whatever(int var1,int var2){
            cout<<"whateverrr\n";
        }
        void getval(){
            cout<<var1<<'\n';
        }
        void setval(int s){
            this->var1=var1;
        }
        void get_priint(){
            cout<<priint<<'\n';
        }
        void set_priint(int i){
            priint=i;
        }
    protected:
        int pro=1234;
    private:
        int priint=1;

};
class child : public Whatever{
    public:
        child(int var1,int var2) : Whatever(var1,var2){
            cout<<"omggg\n";
        }
        void getval(){
            cout<<pro;
        }
};
const pair<int,int> operator + (const pair <int,int> &a, const pair <int,int>&b){
    return {a.first+b.first,a.second+b.second};
}
const ostream& operator << (  ostream& stream, pair <int,int> a){
    stream<<a.first<<' '<<a.second<<'\n';
    return stream;
}
const istream& operator >> ( istream& stream, pair<int,int>&a){
    stream >>a.first>>a.second;
    return stream;
} 
void solve(){
    Whatever omg(12345,221);
    child chi(123,123);
    chi.Whatever::getval();
    chi.var2=1;
    // pair<int,int>a={1,2},b={3,4};
    // pair<int,int>c;
    // cin>>c;
    // cout<<c;
    // cout<<(a+c);
}
signed main(void){
    ac;
    solve();
    return 0;
}
