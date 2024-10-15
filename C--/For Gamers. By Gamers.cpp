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
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

struct Unit {
	ll c, d, h;
};

ll n, m, C;
Unit a[maxn + 2];
ll Best[maxn + 2];

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> C;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i].c >> a[i].d >> a[i].h;
    	Best[a[i].c] = max(Best[a[i].c], a[i].d * a[i].h);
    }
    	
    for (int cost = 1; cost <= C; ++cost)
    	for (int Ccost = cost; Ccost <= C; Ccost += cost)
    		Best[Ccost] = max(Best[Ccost], Best[cost] * (Ccost / cost));
    
    for (int cost = 1; cost <= C; ++cost)
    	Best[cost] = max(Best[cost], Best[cost - 1]);
    	
    // for (int i = 0; i <= C; ++i) 
    	// cout << Best[i] << " ";
    // cout << endl;
    
    cin >> m;
    while (m--) {
    	Unit Mon;
    	cin >> Mon.d >> Mon.h;
    	
    	int pos = upper_bound(Best + 1, Best + 1 + C, Mon.d * Mon.h) - Best;
    	if (pos > C) pos = -1;
    	
    	cout << pos << " "; 
    }
    
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
// https://codeforces.com/problemset/problem/1657/D

