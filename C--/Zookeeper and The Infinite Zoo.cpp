#include<bits/stdc++.h>

using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

#define indexed_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

ll test;
ll a, b;
vector<ll> va, vb;
bool exist;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> test;
    while (test--) {
        cin >> a >> b;
        
        va.clear();
        vb.clear();
        
        if (a > b) {
            cout << "NO" << endl;
            continue;
        }

        for (int x = 0; x < 30; x++) {
            if (a & (1 << x)) va.pb(x);
            if (b & (1 << x)) vb.pb(x);
        }
        
        if (va.size() < vb.size()) {
            cout << "NO" << endl;
            continue;
        }
        
        exist = 1;
        for (int x = 0; x < vb.size(); x++) {
            if (va[x] > vb[x]) {
                exist = 0;
                break;
            }
        }
        
        cout << (exist ? "YES" : "NO") << endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1491/D
