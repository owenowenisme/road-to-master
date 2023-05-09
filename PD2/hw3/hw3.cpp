#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define int unsigned long long
using namespace std;
struct info{
    int id=0;
    int date=0;
    int time=0;
    int sign=0;
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
//int now
void solve(char* filename){
    
    //info data[100000];
    info nothing;
     vector<info>data;
    //freopen(filename,"r",stdin);
    ifstream in(filename);
    string s;
    stringstream ss;
    register int idx=0,id=0,arr[3];
    while(in>>s){
        ss<<s; id=0;
        while(getline(ss,s,',')){
            if(id==1){
                if(s[5]=='i')
                    arr[1]=0;
                else 
                    arr[1]=1;
            }else{
                arr[id]=stol(s);
            }
            id++;
        }
        nothing.id=arr[0];
	//cout<<arr[0]<<'\n';
        nothing.sign=arr[1];
        nothing.time=arr[2];
        arr[2]*=0.0001;
        nothing.date=arr[2];
        idx++;
	data.push_back(nothing);
        ss.clear();
    }
    

    sort(data.begin(),data.end(),cmp);
    register int current_id=data[0].id,current_overload=0;
    register stack<int>st;
    register stack<int>emp;
    st.push(0);
//    #pragma omp parallel for
    for(register int i=0;i<idx;++i){
            if(current_id!=data[i].id){
                cout<<current_id<<','<<current_overload<<','<<st.size()<<'\n';
                st=emp;
		st.push(i);
                current_id=data[i].id,current_overload=0;
            }else{
                if(st.empty()){st.push(i);continue;}
                if(data[st.top()].date==data[i].date){
                    if(data[st.top()].sign==0&&data[i].sign==1){
                        if(data[i].time-data[st.top()].time>800){
			current_overload++;
                        }
                        st.pop();
                    }
                }
                else{
                        st.push(i);
                }
            }
        
    }
//    for(auto o:data)
//	    cout<<o.id<<'\n';
    cout<<current_id<<','<<current_overload<<','<<st.size()<<'\n';
}
signed main(int argc,char *argv[]){ac;
    //now =clock();
    solve(argv[1]);
    return 0;
}
