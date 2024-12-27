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
const int maxn = 2e6;
const int maxa = 2e3;
const int base = 31;

ll test, n, res;
bool P[maxn + 2];
vector<ll> Prime;

void Sieve() {
	memset(P, 1, sizeof(P));
	
	P[0] = P[1] = 0;
	for (int i = 2; i * i <= maxn; ++i) 
		if (P[i])
			for (int j = i * i; j <= maxn; j += i) P[j] = 0;
			
	Prime.pb(0);
	for (int i = 2; i <= maxn; ++i)
		if (P[i]) Prime.pb(i);
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
    	cin >> n;
    	
    	for (int i = 1; i < Prime.size() - 2; ++i)
    		if (Prime[i] * Prime[i + 1] * Prime[i + 2] <= n) res = Prime[i] * Prime[i + 1] * Prime[i + 2];
    		else break;
    		
    	cout << res << endl;
    }
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
