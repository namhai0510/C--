#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

ll q, s;

struct Data {
    ll remain;
    ll sumdigit = 0;
    string num;
};

string Getmin(ll Q, ll S) {
    queue<Data> Qu;
    vector<vector<bool>> v(Q, vector<bool>(S + 1, false));
    
    for (ll i = 1; i <= 9 && i <= S; ++i) {
        ll r = i % Q;
        Qu.push({r, i, to_string(i)});
        v[r][i] = 1;
    }
        
    while (!Qu.empty()) {
        Data current = Qu.front();
        Qu.pop();
        if (current.sumdigit == S and current.remain == 0) {
            return current.num;
        }
        
        for (int i = 0; i <= 9; ++i) {
            int new_rm = (current.remain * 10 + i) % Q;
            int new_sumdigit = current.sumdigit + i;
            if (new_sumdigit <= S and !v[new_rm][new_sumdigit]) {
                v[new_rm][new_sumdigit] = 1;
                Qu.push({new_rm, new_sumdigit, current.num + to_string(i)});
            }
        }
    }
    return "-1";
}
    
int main() {
    nothing
    if (fopen("nmin.inp", "r")) {
        freopen("nmin.inp", "r", stdin);
        freopen("nmin.out", "w", stdout);
    }
    cin >> q >> s;
    
    cout << Getmin(q, s);
    
    return 0;
}
