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

ll test, a, b, k;

ll Prime[maxn + 2];
bool Check[maxn + 2];
void Sieve() {
	memset(Check, 1, sizeof(Check));
	Check[0] = Check[1] = 0;
	
	for (int i = 2; i * i <= maxn; ++i) {
		if (Check[i]) {
			for (int j = i * i; j <= maxn; j += i) Check[j] = 0;
		}
	}
	
	int j = 1;
	for (int i = 2; i <= maxn; ++i) {
		if (Check[i]) {
			Prime[j] = i;
			j++;
		}
	}
}

ll Get(ll x) {
	ll ret = 0;
	
	for (int i = 1; Prime[i] * Prime[i] <= x; ++i) {
		while (x % Prime[i] == 0) {
			ret++;
			x /= Prime[i];
		}
	}
	
	if (x > 1) ret++;
	
	return ret;
}
int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    Sieve();
    cin >> test;
    
    while (test--) {
    	cin >> a >> b >> k;
    	
    	if (k == 1) {
    		if (a > b) swap(a, b);
    		
    		if (a == b || (b % a != 0)) cout << "NO" << endl;
    		else cout << "YES" << endl;
    		
    		continue;
    	}
    	
    	if (Get(a) + Get(b) >= k) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}

// https://codeforces.com/problemset/problem/1538/D
