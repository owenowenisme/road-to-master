#include <bits/stdc++.h>
//#include <omp.h>
//#pragma omp parallel num_threads(16)
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
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ac ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
//#define id get<0>(vec[i])
//#define time get<1>(vec)
//#define date second.second
using namespace std;
//int no
pair<int,pair<long long,int>>nothing;

signed main(int argc,char *argv[]){ac;
    //now =clock();
    
    
    //info vec[100000];
    //freopen(filename,"r",stdin);
    //ifstream in(argv[1]);
    string s;
    stringstream ss;
    register int idx=0,id=0,arr[3];
   register vector<tuple<int, int64_t,int>> vec;
    //vec.reserve(10000000);
    FILE* fp = fopen(argv[1], "r");
    
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char* employee_id_str = strtok(line, ",");
        int employee_id = atoi(employee_id_str);

        char* sign_type = strtok(NULL, ",");
        
        char* time_str = strtok(NULL, ",");
        int64_t time = atoll(time_str);
	int date=time/10000;

        vec.push_back({employee_id, time,date});
    	
    }

    sort(vec.begin(),vec.end());
    int current_id=get<0>(vec[0]),current_overload=0,current_forget=0,hold_idx=-1;
	cout<<vec.size();    
//    #pragma omp parallel for
    for( int i=0;i<vec.size();++i){
	    if(current_id!=get<0>(vec[i])){

                cout<<current_id<<','<<current_overload<<','<<current_forget<<'\n';

                //current_id=vec[i].id,current_overload=0,current_forget=1,hold_idx=i;
            }else{
                if(hold_idx==-1){hold_idx=i;current_forget++;continue;}
                if(get<2>(vec[hold_idx])==get<2>(vec[i])){
                        if(get<1>(vec[i])-get<1>(vec[hold_idx])>800){
			current_overload++;
                        }
			hold_idx=-1;
                        current_forget--;
                }
                else{	hold_idx=i;
                        
			current_forget++;
                }
            }
        
    }
    cout<<current_id<<','<<current_overload<<','<<current_forget<<'\n';
    return 0;
}
