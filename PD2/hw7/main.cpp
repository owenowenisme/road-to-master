#include <bits/stdc++.h>
#define ac ios_base::sync_with_stdio(false), cin.tie(0)
#define mem(a, val) memset(a, val, sizeof(a))
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define int long long
#define F first
#define S second
const int maxn = 1e8;
const double EPS = 1e-15;
using namespace std;
bool cmp(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

void solve(char* filename1, char* filename2, int k) {
    unordered_map<string, set<int>> mp;
    unordered_map<int, double> idfsum;
    
    unordered_map<int,unordered_map<string,double>> tfmp;
    unordered_map<string,double>tmp_mp;
    set<int> tmpset;
    
    ifstream in(filename1);
    stringstream ss;
    string s="", tmp="";

    int id = 0;
    int strnum = 0;

    while (getline(in, s)) {
        int wordnum=0;
        tmp_mp.clear();
        strnum++;
        int i = 0;
        tmp = "";
        for (i = 0; i < s.length(); ++i) {
            if (s[i] == ',') break;
            tmp += s[i];
        }
        id = stoi(tmp);
        tmp = "";
        for (; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
            if (s[i] >= 'a' && s[i] <= 'z')
                tmp += s[i];
            else if (s[i] != ' ') {
                continue;
            } else if (tmp != "") {
                wordnum++;
                mp[tmp].insert(id);
                tmp_mp[tmp]++;//cout<<tmp<<' '<<wordnum<<'\n';
                tmp = "";
            }
        }
        mp[tmp].insert(id);
        tmp_mp[tmp]++;
        if(tmp.length()>0)
            wordnum++;
        for(auto &a:tmp_mp)
             a.second=(double)a.second/(double)wordnum;
        tfmp[id]=tmp_mp;
        // cout<<id<<' '<<wordnum<<'\n';
    }
    map<string,double> realidf;
    ifstream in2(filename2);
    set<int> ans;
    string str = "";
    while (getline(in2, str)) {
        idfsum.clear();
        ss << str;
        while (ss >> s) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            if (mp[s].size() > 0) {
                double idf = log((double)strnum / (double)mp[s].size());
                realidf[s]=idf;
                for (auto a : mp[s]) {
                    if (strnum > mp[s].size()) {
                        // idfsum[a] += idf;
                        idfsum[a]+=tfmp[a][s]*idf;
                    }
                    
                }
            }
        }
        while (ss >> s) {
            // clear stringstream
        }
        vector<pair<double, int>> vec;
        for (auto a : idfsum) {
            vec.push_back({a.second, a.first});
        }
        for (int i = 0; i < k; i++) {
            vec.push_back({-1, -1});
        }

        sort(vec.begin(), vec.end(), cmp);
        for (int i = 0; i < k; i++) {
            cout << vec[i].second << " \n"[i == k - 1];
        }
        vec.clear();
        idfsum.clear();
        ss.clear();
    }
    // cout<<"fkndo"<<strnum;
    // for(auto a:tfmp){
    //     cout<<a.first<<'\n';
    //     for(auto b:a.second){
    //         cout<<b.first<<' '<<b.second<<' '<<realidf[b.first]<<'\n';
    //     }
    //     cout<<"====================\n";
    // }
}
signed main(int argc, char* argv[]) {
    ac;
    int k = stoi(argv[3]);
    solve(argv[1], argv[2], k);
    return 0;
}