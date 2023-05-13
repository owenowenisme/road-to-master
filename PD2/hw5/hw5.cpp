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
void solve(char* filename1,char* filename2){
	unordered_map<string,set<int>>mp;
	set<int>tmpset;
	ifstream in(filename1);
	stringstream ss;
	string s,tmp;
	
	int id=0;
	while(getline(in,s)){
			int i=0;tmp="";
			for(i=0;i<s.length();i++){
				if(s[i]==',') break;
				tmp+=s[i];
			}
			id=stoi(tmp);
			tmp="";
			for(;i<s.length();i++){
				if(s[i]>='A'&&s[i]<='Z'){
					s[i]+=32;
				}
				if(s[i]>='a'&&s[i]<='z')
					tmp+=s[i];
				else if(s[i]!=' '){
					continue;
				}
				else if(tmp!=""){
					mp[tmp].insert(id);
					tmp="";
				}
			}
			mp[tmp].insert(id);
	}
	ifstream in2(filename2);
	set<int>ans;
	string str="";
	int checker =1;
	while(getline(in2,str)){
		ss<<str;
		while(ss>>s){transform(s.begin(),s.end(),s.begin(),::tolower);
			if(checker){
				ans=mp[s];
				checker=0;
			}else{
				tmpset.clear();
				set_intersection(ans.begin(),ans.end(),
								mp[s].begin(),mp[s].end(),inserter(tmpset,tmpset.end()));
				
				if(tmpset.empty()){
					ans.clear();

					break;
				}
				ans=tmpset;
			}
		}
		if(ans.empty()){
			cout<<"-1\n";
		}else{
			vector<int>ansvec;
			for(auto a:ans){
				ansvec.emplace_back(a);
			}
			for(auto a:ansvec){
				cout<<a<<" \n"[a==ansvec.back()];
			}
			
		}
		checker=1;
		ans.clear();
		tmpset.clear();
		while(ss>>s){
		}
		ss.clear();
	}
}
signed main(int argc,char *argv[]){
	ac;
	solve(argv[1],argv[2]);
	return 0;
}