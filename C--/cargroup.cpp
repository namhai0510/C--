#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

ll n, P, L, w[maxn + 2], v[maxn + 2];
double f[maxn + 2];
vector<ll> trace;

double DP(int i){
    if (i > n) return 0;
    if (f[i] != +oo) return f[i];
    ll mnspd = LLONG_MAX / 2;
    ll wei = 0;
    for (int j = i; j <= n; ++j) {
        wei += w[j];
        mnspd = min(mnspd, v[j]);
        
        if (wei > P) break;
        f[i] = min(f[i], DP(j + 1) + (double)L / mnspd);
    }
    return f[i];
}

void Trace(int i) {
    if (i > n) return;
    ll mn = LLONG_MAX;
    ll wei = 0;
    for (int j = i; j <= n; ++j) {
        wei += w[j];
        mn = min(mn, v[j]);
        if (wei > P) break;
        
        if (DP(i) == DP(j + 1) + (double)L / mn){
            cout << i << " ";
            Trace(j + 1);
            break;
        }
    }
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n >> P >> L;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> w[i] >> v[i];
    	
    	f[i] = +oo;
    }
    
    cout << fixed << setprecision(2) << DP(1) << endl;
    Trace(1);
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
