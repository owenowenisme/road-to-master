#include <bits/stdc++.h>
#include <omp.h>
#pragma omp parallel num_threads(16)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#define ac ios_base::sync_with_stdio(false),cin.tie(0)
#define int unsigned int
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
void solve(char* filename){
    //info data[100000];
    info nothing;
    vector<info>data;
    freopen(filename,"r",stdin);
    string s;
    stringstream ss;
    int idx=0,id=0,arr[3];
    while(getline(cin,s)){
        ss<<s; id=0;
        while(getline(ss,s,',')){
            if(id==1){
                if(s=="sign-in")
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
        nothing.date=arr[2]%10000;
        idx++;
	data.push_back(nothing);
        ss.clear();
    }
    

    sort(data.begin(),data.end(),cmp);
    int current_id=data[0].id,current_overload=0,current_forget=0;
    stack<info>st;
    st.push(data[0]);
    #pragma omp parallel for
    for(int i=0;i<idx;++i){
	    //cout<<data[i].id<<'\n';
            if(current_id!=data[i].id){
                cout<<current_id<<','<<current_overload<<','<<st.size()<<'\n';
                while(!st.empty())st.pop();
                st.push(data[i]);
                current_id=data[i].id,current_overload=0,current_forget=0;
            }else{
                if(st.empty()){st.push(data[i]);continue;}
                if(st.top().date==data[i].date){
                    if(st.top().sign==0&&data[i].sign==1){
                        if(data[i].time-st.top().time>800){
			asm volatile(
			"add $1,%0;"
			:[x] "+&r" (current_overload)
			:		
			);
			//current_overload++;
                        }
                        st.pop();
                    }
                }
                else{
                        st.push(data[i]);
                }
            }
        
    }
//    for(auto o:data)
//	    cout<<o.id<<'\n';
    cout<<current_id<<','<<current_overload<<','<<st.size()<<'\n';
}
signed main(int argc,char *argv[]){ac;
    solve(argv[1]);
    return 0;
}