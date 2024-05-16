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

string S;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> S;
    
    string x1, y1, x2, y2;
    int l, r, m1 = 0, m2 = 0;
    bool check1, check2;
    
    x1 = S.substr(0, S.size() / 2); y1 = S.substr(S.size() / 2, S.size() / 2 + 1);
    // cout << x1 << " " << y1 << endl;
    l = 0; r = 0;
    while (r < y1.size()) {
        if (x1[l] == y1[r]) {
            l++; r++;
        }
        else {
            r++;
            m1 = l;
        }
    }
    
    y1.erase(y1.begin() + m1);
    // cout << y1 << endl;
    
    if (y1 == x1) check1 = 1;
    else check1 = 0;
    
    x2 = S.substr(0, S.size() / 2 + 1); y2 = S.substr(S.size() / 2 + 1, S.size() / 2);
    // cout << x2 << " " << y2 << endl;
    l = 0; r = 0;
    while (l < x2.size()) {
        if (x2[l] == y2[r]) {
            l++; r++;
        }
        else {
            l++;
            m2 = r;
        }
    }
    
    x2.erase(x2.begin() + m2);
    // cout << x2 << endl;
    
    if (x2 == y2) check2 = 1;
    else check2 = 0;
    
    if (check1 == 0 && check2 == 0) cout << "NOT POSSIBLE";
    else if (check1 && check2 && x1 != y2) cout << "NOT UNIQUE";
    else if (check1 == 1) cout << x1 << endl;
    else cout << y2 << endl;
    
    return 0;
}
