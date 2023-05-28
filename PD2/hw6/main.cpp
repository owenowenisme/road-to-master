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
bool cmp(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

void solve(char* filename1, char* filename2, int k) {
    unordered_map<string, set<int>> mp;
    unordered_map<int, double> idfsum;
    set<int> tmpset;
    ifstream in(filename1);
    stringstream ss;
    string s, tmp;

    int id = 0;
    int strnum = 0;
    while (getline(in, s)) {
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
                mp[tmp].insert(id);
                tmp = "";
            }
        }

        mp[tmp].insert(id);
    }

    ifstream in2(filename2);
    set<int> ans;
    string str = "";
    int checker = 1;
    while (getline(in2, str)) {
        idfsum.clear();
        ss << str;
        while (ss >> s) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            if (mp[s].size() > 0) {
                double idf = log((double)strnum / (double)mp[s].size());
                for (auto a : mp[s]) {
                    if (strnum > mp[s].size()) {
                        idfsum[a] += idf;
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
}
signed main(int argc, char* argv[]) {
    ac;
    int k = stoi(argv[3]);
    solve(argv[1], argv[2], k);
    return 0;
}