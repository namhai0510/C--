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

ll t, n, m, a[maxn + 2];
ll r[maxn + 2], rp;
double imp = 1.0, p[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n >> m;
    	
    	rp = n; 
    	imp = 1.0;
    	
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	
    	for (int i = n; i >= 1; --i) {
            if (a[i] == i) rp--;
            else break;
        }
    	
    	for (int i = 1; i <= m; ++i) {
    		cin >> r[i] >> p[i];
    		
    		if (r[i] >= rp) {
                imp *= (1.0 - p[i]);
            }
    	}
    	
    	if (!rp) {
            cout << setprecision(6) << fixed << 1.0 << endl;
            continue;
        }
        
        cout << setprecision(6) << fixed <<  (1.0 - imp) << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1461/C